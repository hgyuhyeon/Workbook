import java.util.Scanner;

/* 원 2개를 각각 중심을 나타내는 점과 반지름을 입력하여 두 원이 서로 겹치는지 판단
 * 입력: 10 10 3 \n 12 12 2 \n 출력: 두 원은 서로 겹친다 */
public class circle {
	public static int compareArea(int x1, int y1, int r1, int x2, int y2, int r2) {
		//중점 간 거리 계산
		int x = Math.abs(x2 - x1);
		int y = Math.abs(y2 - y1);
		double distance = Math.sqrt(x*x + y*y);
		//만약 거리보다 반지름의 합이 같거나 작으면 안겹치고 크면 겹침!
		double r = r1 + r2;
		if(r>distance) {
			return 1;
		}
		else {
			return 0;
		}
	}
	public static void main(String[] args) {
		int x1, y1, r1, x2, y2, r2;
		
		System.out.println("첫 번째 원의 중심과 반지름: ");
		Scanner scanner1 = new Scanner(System.in);
		x1 = scanner1.nextInt();
		y1 = scanner1.nextInt();
		r1 = scanner1.nextInt();
		
		System.out.println("두 번째 원의 중심과 반지름: ");
		Scanner scanner2 = new Scanner(System.in);
		x2 = scanner2.nextInt();
		y2 = scanner2.nextInt();
		r2 = scanner2.nextInt();
		int result = compareArea(x1, y1, r1, x2, y2, r2);
		if(result == 1) {
			System.out.println("두 원은 겹칩니다.\n");
		}
		else {
			System.out.println("두 원은 겹치지 않습니다.\n");
		}
	}

}
