// Sender.java
import java.io.*;
import java.net.*;

public class Sender {
    static int d_size = 5;
    static int[] data = {5, 4, 3, 2, 1};

    public static void main(String[] args) {
        try {
            ServerSocket server_socket = new ServerSocket(6666);
            System.out.println("Waiting for the receiver to connect.");
            Socket socket = server_socket.accept();
            System.out.println("Receiver connected.");

            ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());
            ObjectInputStream in = new ObjectInputStream(socket.getInputStream());

            int i = d_size - 1;

            System.out.print("Data: ");
            for(int j=0; j<d_size; j++)
                    System.out.print(data[j]+" | ");
            System.out.println();

            while (i >= 0) 
            {
                //Send data
                out.writeObject(data[i]);
                System.out.println("Sent: " + data[i]);
                System.out.print("Data: ");
                for(int j=0; j<i; j++)
                    System.out.print(data[j]+" | ");
                System.out.println();

                //Receive and check ACK
                String ack = (String) in.readObject();
                int frame_no = Character.getNumericValue(ack.charAt(3));
                if (frame_no != d_size - 1 - i)
                    continue;
                i--;
                Thread.sleep(2000);
            }

            in.close();
            out.close();
            socket.close();
            server_socket.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
