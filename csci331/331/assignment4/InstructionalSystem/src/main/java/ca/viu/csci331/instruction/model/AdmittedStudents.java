package main.java.ca.viu.csci331.instruction.model;

import java.util.*;
import java.io.*;

public class AdmittedStudents
{
	private LinkedList <Student> students = new LinkedList <Student> ();
	private final int capacity;
	private int numberOfStudents;
	
	public AdmittedStudents(int cap)
	{
		capacity = cap;
		numberOfStudents = 0;
	}
	
	public void admit(Student newS)
	{
		if (capacity == numberOfStudents)
		{
			System.out.println("Error: Students database is at it's capacity, please try again later\n");
		}
		else
		{
			students.add(newS);
			numberOfStudents++;
		}
	}
	
	public void cancel(Student s)
	{
		if (students.contains(s))
		{
			int i = students.indexOf(s);
			students.remove(i);
			numberOfStudents--;
		}
		else
		{
			System.out.println("Error: no such student found. Please check your data and try again\n");
		}
	}
	
	public void update(String id, Student newS)
	{
		boolean s = false;
		for (int i = 0; ((i < numberOfStudents) && (!s)); i++)
		{
			if (students.get(i).getID() == id)
			{
				students.get(i).setName(newS.getName());
				students.get(i).setEmail(newS.getEmail());
				s = true;
			}
		}
	}
	
	public void show()
	{
		Student s = new Student();
		System.out.println("All admitted students:\n");
		for (int i = 0; i < numberOfStudents; i++)
		{
			s = students.get(i);
			System.out.print(i);
			System.out.println(":");
			s.show();
		}
	}
	
	public Student searchByName(String n)
	{
		Student temp = new Student();
		for (int i = 0; i < numberOfStudents; i++)
		{
			temp = students.get(i);
			if (temp.getName() == n)
			{
				return temp;
			}
		}
		temp = new Student();
		temp.setName("No such Student found");
		return temp;
	}
	
	public Student searchByID(String id)
	{
		Student temp = new Student();
		for (int i = 0; i < numberOfStudents; i++)
		{
			temp = students.get(i);
			if (temp.getID() == id)
			{
				return temp;
			}
		}
		temp = new Student();
		temp.setName("No such Student found");
		return temp;
	}
	
	public void cancel(String id, String date)
	{
		boolean s = false;
		for (int i = 0; ((i < numberOfStudents) && (s)); i++)
		{
			if (students.get(i).getID() == id)
			{
				students.get(i).cancel(date);
				s = true;
			}
		}
	}
	
	public void admit(String id, String date)
	{
		boolean s = false;
		for (int i = 0; ((i < numberOfStudents) && (s)); i++)
		{
			if (students.get(i).getID() == id)
			{
				students.get(i).admit(date);
				s = true;
			}
		}
	}
	
	public LinkedList <Student> whoIsCancelled(String date)
	{
		LinkedList <Student> canc = new LinkedList <Student> ();
		for (int i = 0; i < numberOfStudents; i++)
		{
			if (students.get(i).isCancelled(date))
			{
				canc.add(students.get(i));
			}
		}
		return canc;
	}
	
	public LinkedList <Student> whoIsAdmitted(String date)
	{
		LinkedList <Student> adm = new LinkedList <Student> ();
		for (int i = 0; i < numberOfStudents; i++)
		{
			if (!students.get(i).isCancelled(date))
			{
				adm.add(students.get(i));
			}
		}
		return adm;
	}
	
	public void write(String filename) throws IOException
	{
		FileWriter out = null;
		try
		{
			out = new FileWriter(filename);
			out.write(numberOfStudents);
			out.write('\n');
			for (int i = 0; i < numberOfStudents; i++)
			{
				students.get(i).write(filename);
			}
		}
		finally
		{
			if (out != null)
			{
				out.close();
			}
		}
	}
	
	public void read(String filename) throws IOException
	{
		FileReader in = null;
		try
		{
			in = new FileReader(filename);
			numberOfStudents = in.read();
			Student temp = new Student();
			for (int i = 0; i < numberOfStudents; i++)
			{
				temp.read(filename);
				students.add(temp);
			}
		}
		finally
		{
			if (in != null)
			{
				in.close();
			}
		}
	}
}
