package main;

import java.io.*;
import lexer.*;

public class Main {
	public static void main(String[] args) throws IOException
	{
		System.setIn(new FileInputStream("Test.txt"));
		Lexer lexer = new Lexer();
		try {
			while (true) {
				Token t = lexer.scan();
				System.out.println(t.toString());
			}
		} catch (IOException e) {
			System.out.println(e.getMessage());
		}
	}
}
