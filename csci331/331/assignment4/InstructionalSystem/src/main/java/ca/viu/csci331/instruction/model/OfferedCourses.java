package main.java.ca.viu.csci331.instruction.model;

import java.util.*;

public class OfferedCourses
{
	private LinkedList <Course> courses = new LinkedList <Course> ();
	private final int capacity;
	private int numberOfCourses;
	
	public OfferedCourses(int cap)
	{
		capacity = cap;
		numberOfCourses = 0;
	}
	
	public void offer(Course newC)
	{
		if (numberOfCourses == capacity)
		{
			System.out.print("Error: Courses database is at it's capacity, please try again later\n");
		}
		else
		{
			boolean c = false;
			for (int i = 0; ((i < numberOfCourses) && (!c)); i++)
			{
				if ((courses.get(i).getName() == newC.getName()) || (courses.get(i).getNumber() == newC.getNumber()) || (courses.get(i).getDesc() == newC.getDesc()))
					c = true;
			}
			if (c)
				System.out.print("Error: This course already exists in the system\n");
			else
			{
				courses.add(newC);
				numberOfCourses++;
			}
		}
	}
	
	public void cancel(Course c)
	{
		if (courses.contains(c))
		{
			int i = courses.indexOf(c);
			courses.remove(i);
			numberOfCourses--;
		}
		else
		{
			System.out.print("Error: no such course found. Please check your data and try again\n");
		}
	}
	
	public void show()
	{
		Course temp = new Course();
		System.out.print("All offered courses:\n");
		for (int i = 0; i < numberOfCourses; i++)
		{
			temp = courses.get(i);
			System.out.print(i);
			System.out.println(":");
			temp.show();
		}
	}
	
	public Course searchByName(String n)
	{
		Course temp = new Course();
		for (int i = 0; i < numberOfCourses; i++)
		{
			temp = courses.get(i);
			if (temp.getName() == n)
			{
				return temp;
			}
		}
		temp = new Course();
		temp.setName("No such Course found");
		return temp;
	}
	
	public Course searchByNumber(String n)
	{
		Course temp = new Course();
		for (int i = 0; i < numberOfCourses; i++)
		{
			temp = courses.get(i);
			if (temp.getNumber() == n)
			{
				return temp;
			}
		}
		temp = new Course();
		temp.setName("No such Course found");
		return temp;
	}
}
