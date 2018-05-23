import java.net.*;
import java.io.*;
import static java.lang.Math.*;

public class Cliente {
  static double sumatoria (double x, int iter) {
    if (iter == 0) return 0.0;
    double suma = 0.0, parcial, coef = 3, argu = 3;
    for (int i = 0; i < iter; i++){
      parcial = ((1 / coef) * sin(argu * x));
      suma = suma + parcial;
      coef = coef + 2;
      argu = argu + 2;
    }
    return suma;
  }

  static int coordenada (double y) {
    double conver = ((300 * (y + 1.4)) / 2.8) - 150 ;
    double coor = 150 - conver;
    return (int)coor;
  }
  
  public static void main(String args[]) {
    byte[] mens = new byte[16];
    try {
      DatagramSocket socketUDP = new DatagramSocket();
      double tamano = PI / 400, y, x;
      int cx, cy;
        for (int j = 0; j < 5; j++) {
          cx = 0;
          for (int i = 0; i <= 800; i++){
            x = ((-PI)+(tamano * i));
            if(x > 3.141592653589793) x = 3.141592653589793;
            if(x > -0.001 && x < 0.001) x = 0.0;
            y = (4 / PI) * ((sin(x)) + sumatoria(x,j));
            if(y > -0.001 && y < 0.001) y = 0.0;
            cx++;
            cy = coordenada(y);
            long tamMsgx = Double.doubleToLongBits((double)cx);
            long tamMsgy = Double.doubleToLongBits((double)cy);
            for(int a = 0; a < 8; a++){
                mens[a] = (byte)((tamMsgx >> ((7 - a) *8)) & 0xff);
            }
            int b = 0;
            for(int c = 8; c < 16; c++){
                mens[c] = (byte)((tamMsgy >> ((7 - b) *8)) & 0xff);
                b++;
            }
            InetAddress hostServidor = InetAddress.getByName("127.0.0.1");
            int puertoServidor = 7000;
        
            DatagramPacket peticion = new DatagramPacket(mens,16,hostServidor,puertoServidor);
//            socketUDP.send(peticion);          
//            System.out.println("Iteracion " + j + " x: " + x + " y: " + y + " (" + cx + "," + cy + ")");
//            for(int d = 0; d < 16; d++){
//              System.out.print((int)mens[d] + " ");
//            }
//            System.out.println();
          }
        }
    }
    catch (SocketException e) {
      System.out.println("Socket: " + e.getMessage());
    }
    catch (IOException e) {
      System.out.println("IO: " + e.getMessage());
    }
  }
}
