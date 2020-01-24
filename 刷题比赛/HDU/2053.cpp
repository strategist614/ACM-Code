import java.math.BigInteger;
import java.util.*;
import java.math.BigDecimal;
public class Main {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
	    Scanner cin = new Scanner(System.in);
	    while(cin.hasNext())
	    {
	    	BigDecimal a,b;
	    	a = cin.nextBigDecimal();
	    	b = cin.nextBigDecimal();
	    	if(a.compareTo(b) == 0) System.out.println("YES");
	    	else System.out.println("NO");
	    }
	}

}