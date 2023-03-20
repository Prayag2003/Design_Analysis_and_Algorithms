import java.util.*;

import javax.lang.model.util.ElementScanner14;

public class temp {

    public static void add(int a, int b) {

        LinkedList<Integer> ll1 = new LinkedList<Integer>();// linklist to store first number
        LinkedList<Integer> ll2 = new LinkedList<Integer>();// linklist to store second number
        LinkedList<Integer> ll3 = new LinkedList<Integer>();// linklist to store addition result of two numbers
        int carry = 0;
        int sum = 0;
        int min = 0;
        int max = 0;
        while (a > 0)// loop for taking the first number in the linked-list-one
        {
            int temp = a % 10;
            ll1.add(temp);
            a = a / 10;
        }
        while (b > 0)// loop for taking the second number in the linked-list-two
        {
            int temp = b % 10;
            ll2.add(temp);
            b = b / 10;
        }

        min = ll1.size() <= ll2.size() ? ll1.size() : ll2.size();// finding the minimum length out of both numbers
        max = ll1.size() >= ll2.size() ? ll1.size() : ll2.size();// finding the maximum length out of both numbers
        for (int i = 0; i < min; i++)// loop for finding the sum upto the min length out of two numbers
        {
            sum = ll1.get(i) + ll2.get(i) + carry;
            carry = sum / 10;
            sum = sum > 9 ? sum % 10 : sum;
            ll3.add(sum);
            sum = 0;
        }
        if (ll1.size() == ll2.size() && carry > 0)// if any end carry occurs and both numbers have same length then add
                                                  // the carry to the resultant linked list
        {
            ll3.add(carry);
        }
        for (int i = min; i < max; i++) // loop for finding sum for remainder part of any one of the numbers
        {
            if (ll1.size() > ll2.size()) {
                sum = ll1.get(i) + carry;
                carry = sum / 10;
                sum = sum > 9 ? sum % 10 : sum;
                ll3.add(sum);
                sum = 0;
            } else if (ll2.size() > ll1.size()) {

                sum = ll2.get(i) + carry;
                carry = sum / 10;
                sum = sum > 9 ? sum % 10 : 0;
                ll3.add(sum);
                sum = 0;
            } else {
                break;
            }
        }
        if (ll1.size() != ll2.size() && carry > 0)// if any end carry occurs and both numbers have unequal length then
                                                  // add carry to the resultant link-list
        {
            ll3.add(carry);
        }
        System.out.println("THE SUM OF THE INTEGERS IS");
        for (int i = ll3.size() - 1; i >= 0; i--) {
            System.out.print(ll3.get(i));
        }
        System.out.println();
    }

    public static void subtract(int a, int b) {
        LinkedList<Integer> ls1 = new LinkedList<Integer>();// linklist to store first number
        LinkedList<Integer> ls2 = new LinkedList<Integer>();// linklist to store second number
        LinkedList<Integer> ls3 = new LinkedList<Integer>();// linklist to store subtraction result of two numbers
        int sub = 0;
        int borrow = 0;int sum1=0;int sum2=0;
        while (a > 0)// loop for taking the first number in the linked-list-one
        {
            int temp = a % 10;
            ls1.add(temp);
            a = a / 10;
        }
        while (b > 0)// loop for taking the second number in the linked-list-two
        {
            int temp = b % 10;
            ls2.add(temp);
            b = b / 10;
        }

        int min = ls1.size() <= ls2.size() ? ls1.size() : ls2.size();// finding the minimum length out of both numbers
        int max = ls1.size() >= ls2.size() ? ls1.size() : ls2.size();// finding the maximum length out of both numbers
        for (int i = 0; i < min; i++) {
            if (ls1.size() > ls2.size()) {
                if (ls1.get(i) < ls2.get(i)) {
                    sub = 10 + ls1.get(i) - ls2.get(i) - borrow;
                    ls3.add(sub);
                    borrow = 1;
                } else {
                    sub = ls1.get(i) - ls2.get(i) - borrow;
                    ls3.add(sub);
                    borrow = 0;
                }
            }
            else if(ls2.size()>ls1.size())
            {
                if (ls1.get(i) < ls2.get(i)) {
                    sub = 10 + ls2.get(i) - ls1.get(i) - borrow;
                    ls3.add(sub);
                    borrow = 1;
                } else {
                    sub = ls2.get(i) - ls1.get(i) - borrow;
                    ls3.add(sub);
                    borrow = 0;
                }
            }
            else
            {
                int t=1;
                for (int j = 0; j < ls1.size(); j++) {
                    sum1=sum1+ls1.get(j)*t;
                    sum2=sum2+ls2.get(j)*t;
                    t=t*10;
                }
                if(sum1>=sum2)
                {
                    if (ls1.get(i) < ls2.get(i)) {
                        sub = 10 + ls1.get(i) - ls2.get(i) - borrow;
                        ls3.add(sub);
                        borrow = 1;
                    } else {
                        sub = ls1.get(i) - ls2.get(i) - borrow;
                        ls3.add(sub);
                        borrow = 0;
                    }
                }
                else
                {
                    if (ls1.get(i) < ls2.get(i)) {
                        sub = 10 + ls2.get(i) - ls1.get(i) - borrow;
                        ls3.add(sub);
                        borrow = 1;
                    } else {
                        sub = ls2.get(i) - ls1.get(i) - borrow;
                        ls3.add(sub);
                        borrow = 0;
                    }
                }
            }

        }
        for (int i = min; i < max; i++) {
            if (ls1.size() > ls2.size()) {
                sub = ls1.get(i) - borrow;
                ls3.add(sub);
                borrow = 0;
            } else {
                sub = ls2.get(i) - borrow;
                ls3.add(sub);
                borrow = 0;
            }
        }
        System.out.println("THE SUBTRACTION OF THE INTEGERS IS");
        for (int i = ls3.size() - 1; i >= 0; i--) {
            System.out.print(ls3.get(i));
        }
        System.out.println();

    }

    public static void multiply(int a, int b) {
        LinkedList<Integer> lm1 = new LinkedList<Integer>();// linklist to store first number
        LinkedList<Integer> lm2 = new LinkedList<Integer>();// linklist to store second number
        while (a > 0)// loop for taking the first number in the linked-list-one
        {
            int temp = a % 10;
            lm1.add(temp);
            a = a / 10;
        }
        while (b > 0)// loop for taking the second number in the linked-list-two
        {
            int temp = b % 10;
            lm2.add(temp);
            b = b / 10;
        }
        int c = 1;
        int mult = 0;
        int carr = 0;
        int summ = 0;
        for (int i = 0; i < lm2.size(); i++) {
            int t = 1 * c;
            for (int j = 0; j < lm1.size(); j++) {
                mult = lm2.get(i) * lm1.get(j) + carr;
                if (j != lm1.size() - 1) {
                    carr = mult / 10;
                    mult = mult % 10;
                }
                summ = summ + t * mult;
                t = t * 10;
                mult = 0;
            }
            carr = 0;
            c = c * 10;
        }
        System.out.println("the multiplication of the numbers is " + summ);
    }

    public static void divide(int a, int b) {

    }

    public static void main(String[] args) {

        add(1100, 200);
        subtract(100, 100);
        multiply(7000,2);
}
}
