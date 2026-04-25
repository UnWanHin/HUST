import java.util.LinkedHashSet;
import java.util.Random;
import java.util.Set;

public class Chapter4_5_Q2_PlateGenerator {
    private static final Random RANDOM = new Random();

    public static void main(String[] args) {
        Set<String> plates = new LinkedHashSet<>();

        while (plates.size() < 5) {
            plates.add(generatePlate());
        }

        System.out.println("随机生成的5个不重复车牌号:");
        for (String plate : plates) {
            System.out.println(plate);
        }
    }

    private static String generatePlate() {
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < 3; i++) {
            char letter = (char) ('A' + RANDOM.nextInt(26));
            sb.append(letter);
        }

        for (int i = 0; i < 4; i++) {
            int digit = RANDOM.nextInt(10);
            sb.append(digit);
        }

        return sb.toString();
    }
}
