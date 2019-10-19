import java.util.*;
import java.io.*;

class Node {
    public int[] maxNutrients;
    public int value;
    public Node left, right;

    public Node(Node l, Node r) {
        value = 0;
        left = l;
        right = r;
    }

    public Node(int v) {
        value = v;
        left = null;
        right = null;
    }
}
public class ccc10s5 {

    public static Node buildTree(String s) {
        s = s.trim();
        if (!s.startsWith("(")) {
            return new Node(Integer.parseInt(s));
        } else {
            s = s.substring(1, s.length() - 1).trim();
            int i;
            if (s.startsWith("(")) {
                int count = 1; i = 1;
                while (count > 0) {
                    if (s.charAt(i) == '(') { count++; }
                    else if (s.charAt(i) == ')') { count--; }
                    i++;
                }
            } else { i = s.indexOf(" "); }
            return new Node(buildTree(s.substring(0, i)), buildTree(s.substring(i + 1)));
        }
    }


    public static void findMax(Node node, int growth) {
        if (node.left == null) {
            Node leaf = node;
            leaf.maxNutrients = new int[growth + 1];
            for (int i = 0; i <= growth; i++) {
                leaf.maxNutrients[i] = leaf.value + i;
            }
        } else {
            Node n = node;
            int max, tmp;
            findMax(n.left, growth);
            int[] leftSubtree = new int[growth + 1];
            for (int i = 0; i <= growth; i++) {
                max = 0;
                for (int j = 0; j <= i; j++) {
                    tmp = Math.min((1 + j) * (1 + j), n.left.maxNutrients[i - j]);
                    if (tmp > max) {
                        max = tmp;
                    }
                }
                leftSubtree[i] = max;
            }
            findMax(n.right, growth);
            int[] rightSubtree = new int[growth + 1];
            for (int i = 0; i <= growth; i++) {
                max = 0;
                for (int j = 0; j <= i; j++) {
                    tmp = Math.min((1 + j) * (1 + j), n.right.maxNutrients[i - j]);
                    if (tmp > max)
                        max = tmp;
                }
                rightSubtree[i] = max;
            }
            n.maxNutrients = new int[growth + 1];
            for (int i = 0; i <= growth; i++) {
                max = 0;
                for (int j = 0; j <= i; j++) {
                    tmp = leftSubtree[j] + rightSubtree[i - j];
                    if (tmp > max) {
                        max = tmp;
                    }
                }
                n.maxNutrients[i] = max;
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Node root = buildTree(sc.nextLine());
        int growth = sc.nextInt();
        findMax(root, growth);
        System.out.println(root.maxNutrients[growth]);
    }
}
