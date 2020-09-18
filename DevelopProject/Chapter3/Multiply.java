package Chapter3;
import java.util.Scanner;
import java.util.InputMismatchException;

public class Multiply {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = 0, m = 0;
		while((n == 0)||(m == 0)) {
			System.out.print("곱하고자 하는 두 수 입력: ");
			try {
				n = scanner.nextInt();
				m = scanner.nextInt();
			}
			catch(InputMismatchException e) {
				System.out.println("실수는 입력하면 안 됩니다.");
				scanner.next();
				scanner.next();
			}
			
		}
		System.out.print(n + "x" + m + "=" + n*m);
		scanner.close();
	}
}
