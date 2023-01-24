package main.java.ca.viu.csci331.instruction.model;

import java.util.Calendar;

public class Instructor
{
	private String name = new String();
	private String insID = new String();
	private String email = new String();
	private String date = new String();
	
	public Instructor()
	{
	}
	
	public Instructor(String n, String id, String mail)
	{
		name = n;
		insID = id;
		email = mail;
		Calendar cal = Calendar.getInstance();
		date = new String("");
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
	}
	
	public String getName()
	{
		return name;
	}
	
	public String getID()
	{
		return insID;
	}
	
	public String getEmail()
	{
		return email;
	}
	
	public void setName(String newName)
	{
		name = newName;
	}

	public void setID(String newID)
	{
		insID = newID;
	}
	
	public void setEmail(String newEmail)
	{
		email = newEmail;
	}
	
	public void show()
	{
		System.out.print("Instructor's name: ");
		System.out.println(name);
		System.out.print("Instructor's ID: ");
		System.out.println(insID);
		System.out.print("Instructor's email: ");
		System.out.println(email);
		System.out.print("Instructor's hire date: ");
		System.out.println(date);
	}
}
