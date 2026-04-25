import java.util.Scanner;

public class Chapter4_5_Q1_LetterFrequencyCounter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入一个英文字符串: ");
        String input = scanner.nextLine();

        int[] counts = new int[26];
        for (int i = 0; i < input.length(); i++) {
            char ch = Character.toLowerCase(input.charAt(i));
            if (ch >= 'a' && ch <= 'z') {
                counts[ch - 'a']++;
            }
        }

        System.out.println("各字母出现次数（不区分大小写）:");
        for (int i = 0; i < counts.length; i++) {
            if (counts[i] > 0) {
                char letter = (char) ('a' + i);
                System.out.println(letter + ": " + counts[i]);
            }
        }

        scanner.close();
    }
}
