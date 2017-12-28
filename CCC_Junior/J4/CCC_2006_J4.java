import java.util.*;
import java.util.Map;

public class CCC_2006_J4 {
	static Set<Integer> visited = new HashSet<Integer>();
	static boolean check = true;

	public static void findcycle(int cur, Map<Integer, Set<Integer>> m) {
		if (visited.contains(cur)) {
			check = false;
			return;
		}
		visited.add(cur);
		for (Integer i : m.get(cur)) {
			findcycle(i, m);
		}
	}

	static int count = 0;

	public static void topsort(Map<Integer, Set<Integer>> m) {
		count++;
		for (int i = 1; i < 8; i++) {
			if (m.get(i).isEmpty()) {
				System.out.print(i + " ");
				Set<Integer> t = m.get(i);
				t.add(0);
				for (int j = 1; j < 8; j++) {
					Set<Integer> temp = m.get(j);
					if (temp.remove(i))
						;
				}
				break;
			}
		}
		if (count < 8) {
			topsort(m);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Map<Integer, Set<Integer>> m = new HashMap<Integer, Set<Integer>>();
		for (int i = 1; i < 8; i++) {
			Set<Integer> temp = new HashSet<Integer>();
			m.put(i, temp);
		}
		Set<Integer> t = m.get(7);
		t.add(1);
		t = m.get(4);
		t.add(1);
		t = m.get(1);
		t.add(2);
		t = m.get(4);
		t.add(3);
		t = m.get(5);
		t.add(3);
		while (true) {
			int start = sc.nextInt();
			int end = sc.nextInt();
			if (start == 0 && end == 0)
				break;
			Set<Integer> temp = m.get(end);
			temp.add(start);
		}
		findcycle(1, m);
		if (check) {
			topsort(m);
		} else {
			System.out.println("Cannot complete these tasks. Going to bed.");
		}
	}
}