import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class FIO{
	public static void readFile(File fi, String token) {
		try {
			Scanner fscanner = new Scanner(fi);
			while(fscanner.hasNextLine()) { 
				String text = fscanner.nextLine(); //파일 전체를 라인 단위로 읽음
				if(text.contains(token)) //해당 라인에 검색어가 있다면
					System.out.println(text); //
			}
			fscanner.close();
		}
		catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
			System.out.println("입출력 오류");
		}
	}
	public static void main(String [] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("전체 경로명이 아닌 파일 이름만 입력하는 경우, 파일은 프로젝트 폴더에 있어야 합니다.");
		System.out.print("대상 파일명 입력>>");
		String fname = scanner.nextLine(); //fname = 파일 이름
		File fi = new File("C:\\Users\\USER\\eclipse-workspace\\Chapter8\\"+fname); //파일 생성
		while(true) { //"그만" 입력 전까지 계속 단어 검색
			System.out.print("검색할 단어나 문장>>");
			String token = scanner.nextLine();
			if(token.equals("그만"))
				break;
			else
				readFile(fi, token); //파일 읽고 결과 도출
		}
		scanner.close();
	}
}
