import java.lang.Math;

public class ejercicio_1{
  static final int MAX = 15000000;
  static double seno = 0, coseno = 0, tangente = 0, logaritmo = 0, raizCuad = 0;

  public static void main(String[] args) {
    process();
  }

  public static void process() {
    for (double i = 0.0; i < MAX; i++) {
      seno += Math.sin(i);
      coseno += Math.cos(i);
      tangente += Math.tan(i);
      logaritmo += Math.log10(i);
      raizCuad += Math.sqrt(i);
    }
  }
}
