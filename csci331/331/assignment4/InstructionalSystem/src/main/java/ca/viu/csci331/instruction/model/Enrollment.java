package main.java.ca.viu.csci331.instruction.model;

public class Enrollment
{
	private Student student;
	private Seminar seminar;
	private double grade;
	
	public Enrollment()
	{
	}
	
	public Enrollment(Student st, Seminar se)
	{
		student = st;
		seminar = se;
	}
	
	public Student getStud()
	{
		return student;
	}
	
	public Seminar getSem()
	{
		return seminar;
	}
	
	public double getGrade()
	{
		return grade;
	}
	
	public void setStud(Student newS)
	{
		student = newS;
	}
	
	public void setSem(Seminar newS)
	{
		seminar = newS;
	}
	
	public void setGrade(double newG)
	{
		grade = newG;
	}
	
	public void show()
	{
		student.show();
		seminar.show();
		System.out.print("Student's grade for this seminar: ");
		System.out.println(grade);
	}
}
