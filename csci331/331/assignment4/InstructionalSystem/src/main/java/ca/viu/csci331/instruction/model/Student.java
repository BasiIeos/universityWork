package main.java.ca.viu.csci331.instruction.model;

import java.util.*;
import java.io.*;

public class Student
{
	private String name = new String();
	private String studentID = new String();
	private String email = new String();
	private boolean cancelled = false;
	private LinkedList <String> timeline = new LinkedList <String> ();
	private int numberOfDates = 0;
	
	public Student()
	{
	}
	
	public Student(String n, String id, String mail)
	{
		name = n;
		studentID = id;
		email = mail;
		numberOfDates++;
		Calendar cal = Calendar.getInstance();
		String date = new String("");
		int year = cal.get(Calendar.YEAR);
	    int month = cal.get(Calendar.MONTH);
	    month++;
	    int day = cal.get(Calendar.DAY_OF_MONTH);
	    int nOD = 0, newM = month;
	    date += Integer.toString(year) + ".";
	    while(newM > 0)
	    {
	    	nOD++;
	    	newM /= 10;
	    }
	    for (int i = 0; i < 2 - nOD; i++)
	    {
	    	date += "0";
	    }
	    date += Integer.toString(month) + ".";
	    int newD = day;
	    nOD = 0;
	    while(newD > 0)
	    {
	    	nOD++;
	    	newD /= 10;
	    }
	    for (int i = 0; i < 2 - nOD; i++)
	    {
	    	date += "0";
	    }
	    date += Integer.toString(day);
	    timeline.add(date);
	}
	
	public String getName()
	{
		return name;
	}
	
	public String getID()
	{
		return studentID;
	}
	
	public String getEmail()
	{
		return email;
	}
	
	public boolean isCancelled()
	{
		return cancelled;
	}
	
	public boolean isCancelled(String date)
	{
		int i = 0;
		boolean ans = true;
		boolean s = false;
		while ((i < numberOfDates) && (!s))
		{
			if (date.compareTo(timeline.get(i)) < 0)
			{
				s = true;
			}
			else
			{
				i++;
				ans = !ans;
			}
		}
		return ans;
	}
	
	public void setName(String newName)
	{
		name = newName;
	}

	public void setID(String newID)
	{
		studentID = newID;
	}
	
	public void setEmail(String newEmail)
	{
		email = newEmail;
	}
	
	public void cancel(String date)
	{
		if (!cancelled)
		{
			cancelled = true;
			timeline.add(date);
			numberOfDates++;
		}
	}
	
	public void admit(String date)
	{
		if (cancelled)
		{
			cancelled = false;
			timeline.add(date);
			numberOfDates++;
		}
	}
	
	public void show()
	{
		System.out.print("Student's name: ");
		System.out.println(name);
		System.out.print("Student's ID: ");
		System.out.println(studentID);
		System.out.print("Student's email: ");
		System.out.println(email);
		if (cancelled)
		{
			System.out.print("Student is cancelled right now\n");
		}
		else
		{
			System.out.print("Student is not cancelled right now\n");
		}
		boolean c = true;
		for (int i = 0; i < numberOfDates; i++)
		{
			if (c)
			{
				System.out.print("Admitted: ");
				System.out.println(timeline.get(i));
			}
			else
			{
				System.out.print("Cancelled: ");
				System.out.println(timeline.get(i));
			}
		}
	}
	
	public void write(String filename) throws IOException
	{
		FileWriter out = null;
		try
		{
			out = new FileWriter(filename);
			out.write(name);
			out.write('\n');
			out.write(studentID);
			out.write('\n');
			out.write(email);
			out.write('\n');
			if (cancelled)
			{
				out.write(1);
			}
			else
			{
				out.write(0);
			}
			out.write('\n');
			out.write(numberOfDates);
			out.write('\n');
			for (int i = 0; i < numberOfDates; i++)
			{
				out.write(timeline.get(i));
				out.write('\n');
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
		BufferedReader in = null;
		try 
		{
			in = new BufferedReader(new FileReader(filename));
			name = in.readLine();
			studentID = in.readLine();
			email = in.readLine();
			int bool = Integer.parseInt(in.readLine());
			if (bool == 1)
			{
				cancelled = true;
			}
			else
			{
				cancelled = false;
			}
			numberOfDates = Integer.parseInt(in.readLine());
			for (int i = 0; i < numberOfDates; i++)
			{
				timeline.add(in.readLine());
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
