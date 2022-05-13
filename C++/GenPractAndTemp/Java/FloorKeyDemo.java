// Java program to demonstrate floorKey() method

import java.util.TreeMap;

public class FloorKeyDemo {
	public static void main(String args[])
	{

		// create an empty TreeMap
		TreeMap<Integer, String> numMap = new TreeMap<Integer, String>();

		// Insert the values
		numMap.put(6, "Six");
		numMap.put(1, "One");
		numMap.put(5, "Five");
		numMap.put(3, "Three");
		numMap.put(8, "Eight");
		numMap.put(10, "Ten");

		// Print the Values of TreeMap
		System.out.println("TreeMap: " + numMap.toString());

		// Get the greatest key mapping of the Map

		// As here 11 is not available it returns 10
		// because ten is less than 11
		System.out.print("Floor Entry of Element 11 is: ");
		System.out.println(numMap.floorKey(10));

		// This will give null
		System.out.print("Floor Entry of Element 0 is: ");
		System.out.println(numMap.floorKey(0));
	}
}
