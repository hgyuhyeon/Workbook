import java.util.Scanner;
//사칙 연산을 입력받아 계산하는 프로그램 예> 2 + 4(빈칸으로 분리하여 입력)
//출력: 2+4의 계산 결과는 6
//연산식을 구분할 때 if-else 문 / switch 문 각각 이용

public class calculate{
	public static double ifcalculator (double num1, double num2, String opal) {
		if(opal.equals("+"))
			return num1 + num2;
		else if(opal.equals("-"))
			return num1 - num2;
		else if(opal.equals("*"))
			return num1 * num2;
		else if(opal.equals("/"))
			return num1 / num2;
		else
			return -1; //Exception Error
			/* 일단 -1로 리턴하게 두긴 했는데 NULL로 리턴할 방법을 못 찾겠음 */

	}
	public static double swcalculator (double num1, double num2, String opal) {
		switch (opal) {
		case "+":
			return num1 + num2;
		case "-":
			return num1 - num2;
		case "*":
			return num1 * num2;
		case "/":
			return num1 / num2;
		default:
			return -1; //Exception Error
			/* 일단 -1로 리턴하게 두긴 했는데 NULL로 리턴할 방법을 못 찾겠음 */
		}
		
	}
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("계산식을 입력하세요(예:2 + 4):");
		double num1 = scanner.nextDouble();
		String opal = scanner.next();
		double num2 = scanner.nextDouble();
		
		if(!opal.equals("+") && !opal.equals("-") && !opal.equals("*") && !opal.equals("/")) {
			System.out.println("입력 오류");
			System.exit(0); //시스템 종료
		} //그래도 입력 예외 처리를 함으로써 최대한 -1로 인한 오류는 없애고자 함
		
		//if-else문 함수
		double iresult = ifcalculator(num1, num2, opal);
		//switch문 함수
		double sresult = swcalculator(num1, num2, opal);
		
		//두 함수의 결과값이 같으면(계산 오류가 없으면) 결과 출력
		if((iresult != -1) && (sresult != -1) && (iresult == sresult)) {
			System.out.println(num1 + opal + num2 + "의 계산 결과는" + sresult);
		}
		else {
			System.out.println("계산 오류\n");
		}
	}
}
