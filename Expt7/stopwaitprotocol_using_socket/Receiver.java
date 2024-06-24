//Receiver.java
import java.io.*;
import java.net.*;
import java.util.ArrayList;

public class Receiver {
    static ArrayList<Integer> data = new ArrayList<>();

    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 6666);
            ObjectInputStream in = new ObjectInputStream(socket.getInputStream());
            ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());

            System.out.println("Receiver:");

            for (int i = 0; i < 5; i++) {
                int received_data = (int) in.readObject();
                System.out.println("Received: " + received_data);
                data.add(received_data);
                System.out.print("Data: ");
                for (int j = data.size() - 1; j >= 0; j--) 
                {
                    System.out.print(data.get(j)+" | ");
                }
                System.out.println();
                out.writeObject("ACK" + i);
            }

            in.close();
            out.close();
            socket.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
