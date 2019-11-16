import java.util.*;

public class CNOTE {

    public static class Notebook {
        public int pages;
        public int price;
        public Notebook(int pages, int price) {
            this.pages = pages;
            this.price = price;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            int k = sc.nextInt();
            int n = sc.nextInt();
            int pagesNeeded = x - y;
            Notebook[] notebooks = new Notebook[n];
            for(int i = 0; i < n; i++) {
                notebooks[i] = new Notebook(sc.nextInt(), sc.nextInt());
            }
            boolean flag = false;
            for(int i = 0; i < n; i++) {
                if(notebooks[i].pages >= pagesNeeded && notebooks[i].price <= k) {
                    System.out.println("LuckyChef");
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                System.out.println("UnluckyChef");
            }
        }
    }
}
