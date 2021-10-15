public class Main {
    public static void main(String[] args) {
        int a = 5, b = 2048;
        System.out.println("Multiplication using shift operator");
        System.out.println("2048 * " + a + " = " + (a << 11));
        System.out.println("Division using shift operator");
        System.out.println("(1 / 512) * " + b + " = " + (b >> 9));
    }
}
