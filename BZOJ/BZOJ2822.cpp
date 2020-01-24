import java.math.*;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        BigInteger c = BigInteger.ONE;
        BigInteger tmp = BigInteger.valueOf(2);
        for(int i = 1;i <= n - 1;i++)
        {
        	BigInteger x = BigInteger.valueOf(i);
        	BigInteger _ = tmp.multiply((tmp.multiply(x)).add(BigInteger.ONE));
        	c = (_.multiply(c)).divide(x.add(tmp));
        }
        System.out.println(c);
    }
}

