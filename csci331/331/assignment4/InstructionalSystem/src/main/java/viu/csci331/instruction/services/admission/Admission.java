package main.java.viu.csci331.instruction.services.admission;
import main.java.ca.viu.csci331.instruction.model.*;

import java.util.*;
import java.io.*;

public class Admission
{
	private final int INF = 999999998;
	private AdmittedStudents list = new AdmittedStudents(INF);
	private static int count = 0;
	
	public Admission()
	{
	}
	
	public void admit(String n, String e)
	{
		String id = new String("");
		int nOD = 0; // number of digits in count
		int newcount = count;
		while (newcount > 0)
		{
			nOD++;
			newcount /= 10;
		}
		for (int i = 0; i < (9 - nOD); i++)
		{
			id += "0";
		}
		if (count != 0)
		{
			id += Integer.toString(count);
		}
		Student s = new Student(n, id, e);
		list.admit(s);
		count++;
	}
	
	public void updateName(String id, String name)
	{
		Student newS = new Student(name, id, list.searchByID(id).getEmail());
		list.update(id, newS);
	}
	
	public void updateEmail(String id, String email)
	{
		Student newS = new Student(list.searchByID(id).getName(), id, email);
		list.update(id, newS);
	}
	
	public void updateNameAndEmail(String id, String name, String email)
	{
		Student newS = new Student(name, id, email);
		list.update(id, newS);
	}
	
	public boolean isCancelled(int dataType, String data)
	{
		// 0 is name, 1 is id
		if (dataType == 0)
		{
			Student newS = list.searchByName(data);
			return newS.isCancelled();
		}
		Student newS = list.searchByID(data);
		return newS.isCancelled();
	}
	
	public LinkedList <Student> isCancelled(String date)
	{
		return list.whoIsCancelled(date);
	}
	
	public LinkedList <Student> isAdmitted(String date)
	{
		return list.whoIsAdmitted(date);
	}
	
	public void admit(String id)
	{
		Calendar cal = Calendar.getInstance();
		String date = new String("");
		int year = cal.get(Calendar.YEAR);
	    int month = cal.get(Calendar.MONTH);
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
		list.admit(id, date);
	}
	
	public void cancel(String id)
	{
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
		list.cancel(id, date);
	}
	
	public void listAdmitted(String date)
	{
		LinkedList <Student> adm = list.whoIsAdmitted(date);
		System.out.print("List of students who were admitted on ");
		System.out.println(date);
		for (int i = 0; i < adm.size(); i++)
		{
			adm.get(i).show();
		}
	}
	
	public void listCancelled(String date)
	{
		LinkedList <Student> canc = list.whoIsCancelled(date);
		System.out.print("List of students who were cancelled on ");
		System.out.println(date);
		for (int i = 0; i < canc.size(); i++)
		{
			canc.get(i).show();
		}
	}
	
	public void write(String filename) throws IOException
	{
		list.write(filename);
	}
	
	public void read(String filename) throws IOException
	{
		list.read(filename);
	}
}
