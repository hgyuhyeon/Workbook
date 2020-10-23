import java.util.Random;
import java.util.Scanner;
import java.util.Vector;

class Nation{
	String country, capital;
	{
		country = "";
		capital = "";
	}
}
public class GetCapital{
	static boolean getElement(Vector<Nation> v, Nation nat) {
		/* 동일한 내용이 있으면 true, 없으면 false */
		if(v.isEmpty())
			return false; //v가 비어있으면 무조건 false 리턴
		for (int i=0;i<v.size();i++) {
			Nation element = v.get(i);
			if(element.country.equals(nat.country))
				return true;
		}
		return false;
	}
	public static void main(String [] args) {
		Scanner scanner = new Scanner(System.in);
		int command = 0;
		Vector<Nation> v = new Vector<Nation>(); //Vector 클래스 생성

		System.out.println("**** 수도 맞추기 게임을 시작합니다 ****");
		while(command != 3) {
			System.out.print("입력: 1, 퀴즈: 2, 종료: 3 >> ");
			command = scanner.nextInt();
			switch(command) {
			case 1:
				System.out.println("현재, "+ v.size() +"개 나라와 수도가 입력되어 있습니다.");
				scanner.nextLine();
				while(true) {
					System.out.print("나라와 수도 입력"+ (v.size() + 1) +">>");
					String cmd = scanner.nextLine();
					if(!cmd.equals("그만")) {
						Nation nat; nat = new Nation(); //객체 생성
						//
						String [] substr = cmd.split(" ");
						nat.country = substr[0];
						nat.capital = substr[1];
						// 문자열 나누기(예: 한국 서울 -> 한국 / 서울)
						if(getElement(v, nat)) //동일한 내용이 있는가?
							System.out.println(nat.country + "는 이미 있습니다!");
						else //없으면 추가
							v.add(nat);
					}
					else
						break;
				}
				break;
			case 2:
				if(v.isEmpty()) { //입력된 내용이 없으면 중지
					System.out.println("입력된 값이 없습니다.");
					break;
				}
				String answer = "";
				while(true) {
					Random rand = new Random();
					int cmd = rand.nextInt(v.size());
					Nation ret = v.get(cmd); //랜덤 인덱스 생성해서 값 받아오기
					System.out.print(ret.country + "의 수도는?");
					answer = scanner.next();
					
					if(!answer.equals("그만")) {
						if(answer.equals(ret.capital))
							System.out.println("정답!!");
						else
							System.out.println("아닙니다!!");
					}
					else
						break; //답에 "그만"을 입력하면 종료
				}
				break;
			case 3:
				break;
			default:
				System.out.println("잘못된 입력입니다.");
				break;
			}
		}
		System.out.println("게임을 종료합니다.");
		scanner.close();
	}
}
