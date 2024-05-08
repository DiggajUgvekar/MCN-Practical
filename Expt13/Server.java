import java.io.*;
import java.net.*;

public class Server {
    public static void main(String[] args) {
        int portNumber = 12345; // Port number the server will listen on

        try {
            // Create a ServerSocket object
            ServerSocket serverSocket = new ServerSocket(portNumber);
            
            System.out.println("Server is running and waiting for client connection...");

            // Wait for a client connection
            Socket clientSocket = serverSocket.accept();
            
            System.out.println("Client connected: " + clientSocket.getInetAddress());

            // Get the input stream of the client socket
            InputStream inputStream = clientSocket.getInputStream();
            BufferedReader in = new BufferedReader(new InputStreamReader(inputStream));

            // Read the message from the client
            String message = in.readLine();
            System.out.println("Received message from client: " + message);

            // Close the sockets
            clientSocket.close();
            serverSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
