package main.java.ca.viu.csci331.instruction.model;

public class Course
{
	private String name = new String();
	private String courseNumber = new String();
	private double credit;
	private String description = new String();
	
	public Course()
	{	
	}
	
	public Course(String n, String cN, double c, String d)
	{
		name = n;
		courseNumber = cN;
		credit = c;
		description = d;
	}
	
	public String getName()
	{
		return name;
	}
	
	public String getNumber()
	{
		return courseNumber;
	}
	
	public double getCredit()
	{
		return credit;
	}
	
	public String getDesc()
	{
		return description;
	}
	
	public void setName(String newName)
	{
		name = newName;
	}
	
	public void setNumber(String newNumber)
	{
		courseNumber = newNumber;
	}
	
	public void setCredit(double newCredit)
	{
		credit = newCredit;
	}
	
	public void setDesc(String newDesc)
	{
		description = newDesc;
	}
	
	public void show()
	{
		System.out.print("Course's name: ");
		System.out.println(name);
		System.out.print("Course's number: ");
		System.out.println(courseNumber);
		System.out.print("Course's credit: ");
		System.out.println(credit);
		System.out.print("Course's description: ");
		System.out.println(description);
	}
}
