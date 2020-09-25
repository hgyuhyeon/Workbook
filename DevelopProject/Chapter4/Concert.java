import java.util.Arrays;
import java.util.Scanner;

public class Concert {
	static String name; //고객명
	static int no; //좌석 번호
	static String[] S = new String[10]; /* 좌석 */
	static String[] A = new String[10];
	static String[] B = new String[10];
	static Scanner scanner = new Scanner(System.in);

	
	public static int PrintMenu() { 
		//메뉴 출력
		System.out.println("명품콘서트홀 예약 시스템입니다.");
		System.out.print("예약:1, 조회:2, 취소:3, 끝내기:4 >>");
		int num = scanner.nextInt();
		return num;
	}
	public static void GetOneSeat(String [] seat) { 
		//1열의 좌석 출력
		for(int i=0; i<seat.length;i++) {
			if(seat[i].equals(""))
				System.out.print(" ---");
			else
				System.out.print(" " + seat[i]);
		}
	}
	public static int FindLoc(String [] seat, String name) { 
		//해당 고객이 예약한 좌석 찾기
		int i;
		for(i=0; i<10;i++) {
			if(seat[i].equals(name))
				break;
		}
		return i;
	}
	public static void Reserve() {
		//1번: 좌석 예약
		System.out.print("좌석구분 S(1), A(2), B(3) >>");
		int num = scanner.nextInt();
		switch(num) {
		case 1: //S석
			System.out.print("S>>");
			GetOneSeat(S);
			System.out.print("\n이름>>");
			name = scanner.next();
			System.out.print("번호(1~10)>>");
			no = scanner.nextInt();
			S[no-1] = name;
			break;
		case 2: //A석
			System.out.print("A>>");
			GetOneSeat(A);
			System.out.print("\n이름>>");
			name = scanner.next();
			System.out.print("번호(1~10)>>");
			no = scanner.nextInt();
			A[no-1] = name;
			break;
		case 3: //B석
			System.out.print("B>>");
			GetOneSeat(B);
			System.out.print("\n이름>>");
			name = scanner.next();
			System.out.print("번호(1~10)>>");
			no = scanner.nextInt();
			B[no-1] = name; //입력한 번호보다 1 낮춰서 저장
			break;
		default:
			System.out.println("입력 오류");
		}
	}
	public static void Inquire() {
		//2번: 조회
		System.out.print("S>>");
		GetOneSeat(S);
		System.out.print("\nA>>");
		GetOneSeat(A);
		System.out.print("\nB>>");
		GetOneSeat(B);
		System.out.println("\n<<<조회를 완료하였습니다.>>>");
	}
	public static void Cancel() {
		//3번: 취소
		System.out.println("좌석구분 S(1), A(2), B(3) >>");
		int num = scanner.nextInt();
		switch(num) {
		case 1: //S석
			System.out.print("S>>");
			GetOneSeat(S);
			System.out.print("\n이름>>");
			name = scanner.next();
			no = FindLoc(S, name);
			S[no] = "";
			break;
		case 2: //A석
			System.out.print("A>>");
			GetOneSeat(A);
			System.out.print("\n이름>>");
			name = scanner.next();
			no = FindLoc(A, name);
			A[no] = "";
			break;
		case 3: //B석
			System.out.print("B>>");
			GetOneSeat(B);
			System.out.print("\n이름>>");
			name = scanner.next();
			no = FindLoc(B, name);
			B[no] = ""; //no는 고객이 작성한 수가 아니라 함수가 찾은 위치므로 그대로 이용
			break;
		default:
			System.out.println("입력 오류");
		}
	}
	public static void main(String [] args) {
		Arrays.fill(S, "");
		Arrays.fill(A, "");
		Arrays.fill(B, "");

		while(true) {
			int num = PrintMenu();
			if(num == 1)
				Reserve(); //예약
			else if(num == 2)
				Inquire(); //조회
			else if(num == 3)
				Cancel(); //취소
			else if(num == 4) {
				scanner.close();
				break; //끝내기
			}
			else
				continue; //반복
		}
	}
}
