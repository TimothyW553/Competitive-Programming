public class defanging_an_ip_address {

    public static String defangIPaddr(String address) {
        String str = "";
        for(int i = 0; i < address.length(); i++) {
            if(address.charAt(i) == '.') {
                str += "[.]";
            } else {
                str += address.charAt(i);
            }
        }
        return str;
    }

    public static void main(String[] args) {
        System.out.println(defangIPaddr("1.1.1.1"));
    }
}
