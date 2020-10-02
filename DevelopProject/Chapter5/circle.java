import java.util.Scanner;

/* 원 2개를 각각 중심을 나타내는 점과 반지름을 입력하여 두 원이 서로 겹치는지 판단
 * 입력: 10 10 3 \n 12 12 2 \n 출력: 두 원은 서로 겹친다 */
class Distance{
	static double getDistance(int x1, int y1, int x2, int y2) {
		//중점 간 거리 계산
		int x = Math.abs(x2 - x1);
		int y = Math.abs(y2 - y1);
		double distance = Math.sqrt(x*x + y*y);
		return distance;
	}
}
class Compare extends Distance {
	static int compareArea(int x1, int y1, int r1, int x2, int y2, int r2) {
		//만약 거리보다 반지름의 합이 같거나 작으면 안겹치고 크면 겹침!
		double distance = Distance.getDistance(x1, y1, x2, y2);
		double r = r1 + r2;
		if(r>distance) {
			return 1;
		}
		else {
			return 0;
		}
	}
}
public class circle {
	public static void main(String[] args) {
		int x1, y1, r1, x2, y2, r2;
		Scanner scanner = new Scanner(System.in);

		System.out.println("첫 번째 원의 중심과 반지름: ");
		x1 = scanner.nextInt();
		y1 = scanner.nextInt();
		r1 = scanner.nextInt();
		
		System.out.println("두 번째 원의 중심과 반지름: ");
		x2 = scanner.nextInt();
		y2 = scanner.nextInt();
		r2 = scanner.nextInt();
		int result = Compare.compareArea(x1, y1, r1, x2, y2, r2);
		if(result == 1) {
			System.out.println("두 원은 겹칩니다.\n");
		}
		else {
			System.out.println("두 원은 겹치지 않습니다.\n");
		}
		scanner.close();
	}

}
