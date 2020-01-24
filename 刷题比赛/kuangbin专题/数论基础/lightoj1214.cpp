import java.util.*;
import java.math.*;
public class Main {
    
	public static void main(String[] args) {
		// TODO 自动生成的方法存根
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        int flag = 0;
        while(T-- > 0)
        {
        	flag ++;
        	BigInteger a,b,c,d;
        	int xx = 0;
        	int yy = 0;
        	c = BigInteger.ZERO;
        	d = BigInteger.ZERO;
        	a = cin.nextBigInteger();
        	b = cin.nextBigInteger();
        	if(a.compareTo(BigInteger.ZERO) == -1) {c = c.subtract(a);xx = 1;}
            if(b.compareTo(BigInteger.ZERO) == -1) {d = d.subtract(b);yy = 1;}
            if(xx == 1) a = c;
            if(yy == 1) b = d;
        	if(a.mod(b) == BigInteger.ZERO)
        	System.out.println("Case "+flag+":"+" divisible");
        	else System.out.println("Case "+flag+":"+" not divisible");
        }
	}

}
