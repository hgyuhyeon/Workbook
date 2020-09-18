package Chapter3;
import java.util.Scanner;
import java.util.Random;

public class RSP {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("컴퓨터와 가위 바위 보 게임을 합니다.");
		String s = null;
		while(true) {
			System.out.print("가위 바위 보! >> ");
			s = scanner.next();
			if(s.equals("그만")) {
				System.out.println("게임을 종료합니다...");
				break;
			}
			if((!s.equals("가위"))&&(!s.equals("바위"))&&(!s.equals("보"))) {
				System.out.println("잘못된 입력입니다.");
				continue;
			}
			
			int u = -1;
			switch(s) {
			case "가위":
				u = 0;
				break;
			case "바위":
				u = 1;
				break;
			case "보":
				u = 2;
				break;
			default:
				break;
			}
			
			String cs[] = new String[3];
			cs[0] = "가위"; cs[1] = "바위"; cs[2] = "보"; //출력 시 컴퓨터 요소 대조
			Random rd = new Random();
			int c = rd.nextInt(3); //컴퓨터의 가위바위보 결과
			/* 0 = 가위, 1 = 바위, 2 = 보 */
			
			//c = 컴퓨터, u = 사용자
			if((u == 2 && c == 0) != ((u == 0 && c == 2) || (u > c))) {
				System.out.println("사용자 = " + s + ", 컴퓨터 = " + cs[c] + ", 사용자가 이겼습니다.");
			} //사용자 win
			else if((u == 2 && c == 0) || (u < c)) {
				System.out.println("사용자 = " + s + ", 컴퓨터 = " + cs[c] + ", 컴퓨터가 이겼습니다.");
			} //컴퓨터 win
			else {
				System.out.println("사용자 = " + s + ", 컴퓨터 = " + cs[c] + ", 비겼습니다.");
			} //비김
		} //while
		scanner.close();
	}
}
