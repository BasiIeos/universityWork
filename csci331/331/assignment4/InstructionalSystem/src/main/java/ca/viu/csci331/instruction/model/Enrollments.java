package main.java.ca.viu.csci331.instruction.model;

import java.util.*;

public class Enrollments
{
	private LinkedList <Enrollment> enrollments = new LinkedList <Enrollment> ();
	private final int capacity;
	private int numberOfEnrollments;
	
	public Enrollments(int cap)
	{
		capacity = cap;
		numberOfEnrollments = 0;
	}
	
	public void enroll(Enrollment newE)
	{
		if (numberOfEnrollments == capacity)
		{
			System.out.println("Error: Enrollments database is at it's capacity, please try again later\n");
		}
		else
		{
			enrollments.add(newE);
			numberOfEnrollments++;
		}
	}
	
	public void cancel(Enrollment e)
	{
		if (enrollments.contains(e))
		{
			int i = enrollments.indexOf(e);
			enrollments.remove(i);
			numberOfEnrollments--;
		}
		else
		{
			System.out.println("Error: no such enrollment found. Please check your data and try again\n");
		}
	}
	
	public void show()
	{
		Enrollment temp = new Enrollment();
		System.out.println("All enrollments:\n");
		for (int i = 0; i < numberOfEnrollments; i++)
		{
			temp = enrollments.get(i);
			System.out.print(i);
			System.out.println(":");
			temp.show();
		}
	}
}
