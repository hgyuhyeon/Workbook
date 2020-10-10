import java.lang.Math;
import java.util.Scanner;

class Person{
	String name; //이름
	int[] nums = new int[3]; //난수 배열
	void Makenum() {
		for(int i=0;i<3;i++) {
			nums[i] = (int) (Math.random()*3+1); //1~3 중 1개의 숫자 생성
			System.out.print(nums[i]+"   "); //해당 숫자 출력
		}
	}
	boolean CheckEquals() {
		for(int i=1; i<3; i++)
			if(nums[i-1] != nums[i]) { //0번째 - 1번째가 다르면 false, 1번째 - 2번째가 다르면 false
				System.out.println("아쉽군요!");
				return false;
				}
		System.out.println(name + "님이 이겼습니다!");
		return true; //0-1도 같고 1-2도 같으면 0-2도 같으므로 true
	}
}
public class Gamenum{
		public static void main(String [] args) {
		Person ps1 = new Person();
		Person ps2 = new Person();
		Scanner scanner = new Scanner(System.in);
		System.out.print("1번째 선수 이름>> ");
		ps1.name = scanner.nextLine();
		System.out.print("2번째 선수 이름>> ");
		ps2.name = scanner.nextLine();
		
		while(true) {
			System.out.print("["+ ps1.name +"]");
			scanner.nextLine();
			ps1.Makenum();
			if(ps1.CheckEquals() == true)
				break;
			System.out.print("["+ ps2.name +"]");
			scanner.nextLine();
			ps2.Makenum();
			if(ps2.CheckEquals() == true)
				break;
			
		}
		scanner.close();
	}
}
