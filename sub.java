import java.util.*;

public class sub {

    public static LinkedList<Integer> clonell(LinkedList<Integer> list) {
        LinkedList<Integer> newList = new LinkedList<>();
        Iterator<Integer> iterator = list.iterator();

        while (iterator.hasNext()) {
            Integer element = iterator.next();
            // Create a new object or copy the object here if it is not a primitive type
            Integer newElement = Integer.valueOf(element.intValue());
            newList.add(newElement);
        }

        // newList now contains a deep copy of the originalList
        return newList;
    }

    public static LinkedList<Integer> Add(LinkedList<Integer> ll1, LinkedList<Integer> ll2) {
        LinkedList<Integer> ll = new LinkedList<>();
        LinkedList<Integer> l1 = new LinkedList<Integer>();
        LinkedList<Integer> l2 = new LinkedList<Integer>();
        l1 = clonell(ll1);
        l2 = clonell(ll2);
        // (-l1)+(-l2) = -(l1 + l2)
        // if(l1.get(0) < 0 && l2.get(0) < 0){
        // l1.set(0, -l1.get(0));
        // l2.set(0, -l2.get(0));
        // ll = Add(l1,l2);
        // ll.set(ll.size() - 1, -ll.getLast());
        // return ll;
        // }

        // (-l1)+(+l2) = (+l2)-(+l1)
        if (l1.get(0) < 0 && l2.get(0) >= 0) {
            l1.set(0, -l1.get(0));
            ll = Subtract(l2, l1);
            return ll;
        }
        // (+l1)+(-l2) = (+l1)-(+l2)
        else if (l1.get(0) >= 0 && l2.get(0) < 0) {
            l2.set(0, -l2.get(0));
            ll = Subtract(l1, l2);
            return ll;
        }
        int i = l1.size() - 1, j = l2.size() - 1, carry = 0;
        while (i >= 0 && j >= 0) {
            int sum = Math.abs(l1.get(i)) + Math.abs(l2.get(j)) + carry;
            carry = sum / 10;
            sum %= 10;
            ll.add(sum);
            i--;
            j--;
        }
        while (i >= 0) {
            int sum = Math.abs(l1.get(i)) + carry;
            carry = sum / 10;
            sum = sum % 10;
            ll.add(sum);
            i--;
        }
        while (j >= 0) {
            int sum = Math.abs(l2.get(j)) + carry;
            carry = sum / 10;
            sum = sum % 10;
            ll.add(sum);
            j--;
        }

        if (carry != 0) {
            int sum = carry;
            carry = sum / 10;
            sum = sum % 10;
            ll.add(sum);
        }
        if (l1.get(0) < 0 && l2.get(0) < 0) {
            // String s = "-"+sum;
            // ll.add(Integer.parseInt(s));
            ll.set(ll.size() - 1, -ll.getLast());
        }

        return ll;
    }

    public static LinkedList<Integer> Subtract(LinkedList<Integer> ll1, LinkedList<Integer> ll2) {
        LinkedList<Integer> ll = new LinkedList<>();
        LinkedList<Integer> l1 = new LinkedList<Integer>();
        LinkedList<Integer> l2 = new LinkedList<Integer>();
        l1 = clonell(ll1);
        l2 = clonell(ll2);
        // (+l1)-(-l2) = (+l1)+(+l2)
        if (l1.get(0) >= 0 && l2.get(0) < 0) {
            l2.set(0, -l2.get(0));
            ll = Add(l1, l2);
            return ll;
        }
        // (-l1)-(+l2) = (-l1)+(-l2)
        else if (l1.get(0) < 0 && l2.get(0) >= 0) {
            l2.set(0, -l2.get(0));
            ll = Add(l1, l2);
            return ll;
        }
        if (l1.size() < l2.size() || (l1.size() == l2.size() && Math.abs(l1.get(0)) < Math.abs(l2.get(0)))) {
            ll = Subtract(l2, l1);
            ll.set(ll.size() - 1, -ll.getLast());
            return ll;
        }
        int i = l1.size() - 1, j = l2.size() - 1, borrow = 0;
        while (i >= 0 && j >= 0) {
            // int diff = Math.abs(Math.abs(l1.get(i)) - Math.abs(l2.get(j))) - borrow;
            int diff = Math.abs(l1.get(i)) - Math.abs(l2.get(j)) - borrow;
            borrow = 0;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            }
            ll.add(diff);
            i--;
            j--;
        }

        while (i >= 0) {
            int diff = Math.abs(l1.get(i)) - borrow;
            borrow = 0;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            }
            ll.add(diff);
            i--;
        }

        while (j >= 0) {
            int diff = Math.abs(l2.get(j)) - borrow;
            borrow = 0;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            }
            ll.add(diff);
            j--;
        }
        // Remove the Zeros in start of the number after subtraction
        while (!ll.isEmpty() && ll.getLast() == 0) {
            ll.removeLast();
        }
        // if 0 is ans
        if (ll.isEmpty()) {
            ll.add(0);
        }

        if (l1.get(0) < 0 && l2.get(0) < 0) {
            // String s = "-"+sum;
            // ll.add(Integer.parseInt(s));
            ll.set(ll.size() - 1, -ll.getLast());
        }
        // if(l1.size() == l2.size() && l1.get(0)<l2.get(0)){
        // ll.set(ll.size()-1, -ll.getLast());
        // }
        // if(flag){
        // ll.set(ll.size()-1, -ll.getLast());
        // }
        return ll;
    }

    public static LinkedList<Integer> Multiply(LinkedList<Integer> ll1, LinkedList<Integer> ll2) {
        LinkedList<Integer> ll = new LinkedList<>();
        LinkedList<Integer> l1 = new LinkedList<Integer>();
        LinkedList<Integer> l2 = new LinkedList<Integer>();
        l1 = clonell(ll1);
        l2 = clonell(ll2);
        if (l1.getFirst() < 0 && l2.getFirst() < 0) {
            l1.set(0, -l1.get(0));
            l2.set(0, -l2.get(0));
            ll = Multiply(l1, l2);
            return ll;
        } else if (l1.getFirst() < 0 && l2.getFirst() >= 0) {
            l1.set(0, -l1.get(0));
            ll = Multiply(l1, l2);
            ll.set(0, -ll.getFirst());
            return ll;
        } else if (l1.getFirst() >= 0 && l2.getFirst() < 0) {
            l2.set(0, -l2.get(0));
            ll = Multiply(l1, l2);
            ll.set(0, -ll.getFirst());
            return ll;
        }
        for (int i = 0; i < ll1.size() + ll2.size(); i++) {
            ll.add(0);
        }
        for (int i = ll1.size() - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = ll2.size() - 1; j >= 0; j--) {
                int product = ll1.get(i) * ll2.get(j) + carry + ll.get(i + j + 1);
                carry = product / 10;
                ll.set(i + j + 1, product % 10);
            }
            ll.set(i, carry);
        }
        while (ll.size() > 1 && ll.getFirst() == 0) {
            ll.removeFirst();
        }
        return ll;
    }

    public static void iterateListReverse(LinkedList<Integer> linkedList) {
        for (int i = linkedList.size() - 1; i >= 0; i--) {
            System.out.print(linkedList.get(i));
        }
        System.out.println();
    }

    public static void iterateList(LinkedList<Integer> linkedList) {
        for (int i = 0; i < linkedList.size(); i++) {
            System.out.print(linkedList.get(i));
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList<Integer> ll1 = new LinkedList<>();
        LinkedList<Integer> ll2 = new LinkedList<>();
        String num1 = sc.next();
        String num2 = sc.next();
        String s1;
        if (num1.charAt(0) == '-') {
            s1 = "" + num1.charAt(0) + num1.charAt(1);
            ll1.add(Integer.parseInt(s1));
            for (int i = 2; i < num1.length(); i++) {
                ll1.add(Integer.valueOf(Character.getNumericValue(num1.charAt(i))));
            }
        } else {
            s1 = "" + num1.charAt(0);
            ll1.add(Integer.parseInt(s1));
            for (int i = 1; i < num1.length(); i++) {
                ll1.add(Integer.valueOf(Character.getNumericValue(num1.charAt(i))));
            }
        }

        String s2;
        if (num2.charAt(0) == '-') {
            s2 = "" + num2.charAt(0) + num2.charAt(1);
            ll2.add(Integer.parseInt(s2));
            for (int i = 2; i < num2.length(); i++) {
                ll2.add(Integer.valueOf(Character.getNumericValue(num2.charAt(i))));
            }
        } else {
            s2 = "" + num2.charAt(0);
            ll2.add(Integer.parseInt(s2));
            for (int i = 1; i < num2.length(); i++) {
                ll2.add(Integer.valueOf(Character.getNumericValue(num2.charAt(i))));
            }
        }

        System.out.println();

        // iterateList(ll1);
        // iterateList(ll2);
        System.out.println("Addition: ");
        LinkedList<Integer> add = new LinkedList<>();
        add = Add(ll1, ll2);
        System.out.println(add);
        iterateListReverse(add);

        System.out.println("Subtraction: ");
        LinkedList<Integer> sub = new LinkedList<>();
        sub = Subtract(ll1, ll2);
        System.out.println(sub);
        iterateListReverse(sub);

        System.out.println("Multiplication: ");
        LinkedList<Integer> mul = new LinkedList<>();
        mul = Multiply(ll1, ll2);
        System.out.println(mul);
        iterateList(mul);
    }
}
