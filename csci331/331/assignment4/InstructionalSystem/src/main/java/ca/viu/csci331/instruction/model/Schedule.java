package main.java.ca.viu.csci331.instruction.model;

public class Schedule
{
	private String day = new String();
	private int hour;
	private int minute;
	private int duration;
	private Room room = new Room();
	
	public Schedule()
	{
	}
	
	public Schedule(String da, int h, int m, int d, Room r)
	{
		day = da;
		hour = h;
		minute = m;
		duration = d;
		room = r;
	}
	
	public String getDay()
	{
		return day;
	}
	
	public int getHour()
	{
		return hour;
	}
	
	public int getMinute()
	{
		return minute;
	}
	
	public int getDur()
	{
		return duration;
	}
	
	public Room getRoom()
	{
		return room;
	}
	
	public void setDay(String newD)
	{
		day = newD;
	}
	
	public void setHour(int newH)
	{
		hour = newH;
	}
	
	public void setMinute(int newM)
	{
		minute = newM;
	}
	
	public void setDur(int newD)
	{
		duration = newD;
	}
	
	public void setRoom(Room newR)
	{
		room = newR;
	}
	
	public void show()
	{
		System.out.print("Day: ");
		System.out.println(day);
		System.out.print("Hour: ");
		System.out.println(hour);
		System.out.print("Minute: ");
		System.out.println(minute);
		System.out.print("Duration: ");
		System.out.println(duration);
		System.out.println("Room: ");
		room.show();
	}
}
