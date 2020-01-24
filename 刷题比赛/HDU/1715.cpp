import java.util.*;
import java.math.*;
public class Main {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
        Scanner cin = new Scanner(System.in);
        int t = cin.nextInt();
        BigInteger[] fi;
        fi = new BigInteger[1005];
        fi[1] = BigInteger.valueOf(1);
        fi[2] = BigInteger.valueOf(1);
        for(int i =3;i<=1000;i++)
        	fi[i] = fi[i-1].add(fi[i-2]);
        while(t-- > 0)
        {
        	int n = cin.nextInt();
        	System.out.println(fi[n]);
        }
	}

}
