package main.java.viu.csci331.instruction.services.administration;

import main.java.ca.viu.csci331.instruction.model.*;
import java.util.*;

public class Administration
{
	private final int INF = 999999998;
	private Rooms rooms = new Rooms(INF);
	private Schedules schedules = new Schedules(INF);
	private Seminars sem = new Seminars(INF);
	private OfferedCourses oc = new OfferedCourses(INF);
	private Instructors ins = new Instructors(INF);
	private static int countI = 0;
	private static int countS = 0;
	
	public Administration()
	{
	}
	
	public void hireIns(String name, String email)
	{
		String id = new String("");
		int nOD = 0; // number of digits in count
		int newcount = countI;
		while (newcount > 0)
		{
			nOD++;
			newcount /= 10;
		}
		for (int i = 0; i < (9 - nOD); i++)
		{
			id += "0";
		}
		if (countI != 0)
		{
			id += Integer.toString(countI);
		}
		Instructor i = new Instructor(name, id, email);
		ins.hire(i);
		countI++;
	}
	
	public void terminateIns(String id)
	{
		Instructor i = ins.searchByID(id);
		ins.terminate(i);
	}
	
	public void updateIns(String id, String newName, String newEmail)
	{
		ins.setName(id, newName);
		ins.setEmail(id, newEmail);
	}
	
	public Instructor getByNameIns(String name)
	{
		Instructor i = ins.searchByName(name);
		return i;
	}
	
	public Instructor getByIDIns(String id)
	{
		Instructor i = ins.searchByID(id);
		return i;
	}
	
	public void listIns()
	{
		ins.show();
		// since the hire date always grows, the instructors array is always sorted, no need for sorting
	}
	
	
	public void offerCourse(String name, String courseNumber, double credit, String description)
	{
		Course c = new Course(name, courseNumber, credit, description);
		oc.offer(c);
	}
	
	public void cancelCourse(String number)
	{
		Course c = oc.searchByNumber(number);
		oc.cancel(c);
	}
	
	public void updateCourse(String number, String newName, double newCredit, String newDesc)
	{
		Course c = oc.searchByNumber(number);
		oc.cancel(c);
		c = new Course(newName, number, newCredit, newDesc);
		oc.offer(c);
	}
	
	public void updateCourse(String name, String newNumber)
	{
		Course c = oc.searchByName(name);
		oc.cancel(c);
		c.setNumber(newNumber);
		oc.offer(c);
	}
	
	public void listCourse()
	{
		oc.show();
	}
	
	public Course getByNumberCourse(String number)
	{
		Course c = oc.searchByNumber(number);
		return c;
	}

	public Course getByNameCourse(String name)
	{
		Course c = oc.searchByName(name);
		return c;
	}
	
	
	public void addRoom(int roomNo, int buildingNo, int capacity)
	{
		Room r = new Room(roomNo, buildingNo, capacity);
		rooms.add(r);
	}
	
	public void removeRoom(int roomNo, int buildingNo)
	{
		Room r = rooms.getRoom(roomNo, buildingNo);
		rooms.remove(r);
	}
	
	public void updateRoom(int oldRoom, int oldBuilding, int newRoom, int newBuilding, int newCap)
	{
		Room oldR = rooms.getRoom(oldRoom, oldBuilding);
		Room newR = new Room(newRoom, newBuilding, newCap);
		rooms.update(oldR,  newR);
	}
	
	public void roomsInBuilding(int buildingNo)
	{
		rooms.showBuilding(buildingNo);
	}
	
	public void roomsOfCapacity(int cap)
	{
		rooms.showCapacity(cap);
	}
	
	
	public void addSchedule(String day, int hour, int minute, int duration, int roomNo, int buildingNo)
	{
		Room r = rooms.getRoom(roomNo, buildingNo);
		if (r.getRoom() == -1)
			System.out.println("No such room exists in the system. Please add the room if it's not in the system or check your data");
		else
		{
			Schedule s = new Schedule(day, hour, minute, duration, r);
			schedules.add(s);
		}
	}
	
	public void removeSchedule(String day, int hour, int minute, int duration, int roomNo, int buildingNo)
	{
		Room r = rooms.getRoom(roomNo, buildingNo);
		if (r.getRoom() == -1)
			System.out.println("No such room exists in the system. Please check your data");
		else
		{
			Schedule s = new Schedule(day, hour, minute, duration, r);
			schedules.remove(s);
		}
	}
	
	public void listSchByRoom(int roomNo, int buildingNo)
	{
		Room r = rooms.getRoom(roomNo, buildingNo);
		if (r.getRoom() == -1)
			System.out.println("No such room exists in the system. Please check your data");
		else
		{
			System.out.println("List of available schedules for this room:");
			LinkedList <Schedule> sch = schedules.checkRoom(r);
			for (int i = 0; i < sch.size(); i++)
			{
				if (!sem.checkSch(sch.get(i)))
				{
					sch.get(i).show();
				}
			}
		}
	}
	
	public void listSchByCap(int cap)
	{
		LinkedList <Room> r = rooms.checkCap(cap);
		for (int i = 0; i < r.size(); i++)
		{
			System.out.print("This room has capacity greater than or equal to ");
			System.out.print(cap);
			System.out.println(":");
			listSchByRoom(r.get(i).getRoom(), r.get(i).getBuilding());
		}
	}
	
	public void listSchByTime(String day, int hour, int minute, int duration)
	{
		LinkedList <Room> r = rooms.checkCap(10000000); // put all rooms in here
		System.out.println("List of schedules for this time and duration:");
		for (int j = 0; j < r.size(); j++)
		{
			LinkedList <Schedule> sch = schedules.checkRoom(r.get(j));
			for (int i = 0; i < sch.size(); i++)
			{
				if (((sch.get(i).getDay() == day) && (sch.get(i).getHour() == hour) && (sch.get(i).getMinute() == minute) && (sch.get(i).getDur() == duration)) && (!sem.checkSch(sch.get(i))))
				{
					sch.get(i).show();
				}
			}
		}
	}
	
	public void listSchByCapAndTime(int cap, String day, int hour, int minute, int duration)
	{
		System.out.println("List of schedules for this time and duration in rooms with greater or equal capacity:\n");
		LinkedList <Room> r = rooms.checkCap(cap);
		for (int j = 0; j < r.size(); j++)
		{
			LinkedList <Schedule> sch = schedules.checkRoom(r.get(j));
			for (int i = 0; i < sch.size(); i++)
			{
				if (((sch.get(i).getDay() == day) && (sch.get(i).getHour() == hour) && (sch.get(i).getMinute() == minute) && (sch.get(i).getDur() == duration)) && (!sem.checkSch(sch.get(i))))
				{
					sch.get(i).show();
				}
			}
		}
	}
	
	
	public void addSeminar(String cNo, String iID, int cap)
	{
		Course c = oc.searchByNumber(cNo);
		Instructor i = ins.searchByID(iID);
		if (c.getName() == "No such Course found")
		{
			System.out.println("Error: no such course found, please try again");
		}
		else if (i.getName() == "No such Instructor found")
		{
			System.out.println("Error: no such instructor found, please try again");
		}
		else
		{
			String id = new String("");
			int nOD = 0; // number of digits in count
			int newcount = countS;
			while (newcount > 0)
			{
				nOD++;
				newcount /= 10;
			}
			for (int j = 0; j < (9 - nOD); j++)
			{
				id += "0";
			}
			if (countS != 0)
			{
				id += Integer.toString(countS);
			}
			Seminar s = new Seminar(id, c, cap, i);
			sem.add(s);
		}
	}
	
	public void cancelSeminar(String semID)
	{
		Seminar s = sem.searchByID(semID);
		sem.cancel(s);
	}
	
	public void updateSeminar(String semID, String newIID, String newCNo)
	{
		Instructor i = ins.searchByID(newIID);
		Course c = oc.searchByNumber(newCNo);
		if (i.getName() == "No such Instructor found")
		{
			System.out.println("Error: no such instructor found, please try again");
		}
		else if (c.getName() == "No such Course found")
		{
			System.out.println("Error: no such course found, please try again");
		}
		else
		{
			sem.setIns(semID, i);
			sem.setC(semID, c);
		}
	}
	
	public void addSchToSem(String semID, String day, int hour, int minute, int duration, int roomNo, int buildingNo)
	{
		Seminar s = sem.searchByID(semID);
		Room r = rooms.getRoom(roomNo, buildingNo);
		if (r.getRoom() == -1)
		{
			System.out.println("Error: no such room found in the system. Add the room to the system or check your data.");
		}
		else if (r.getCapacity() < s.getCap())
		{
			System.out.println("Error: room doesn't have enough space for the seminar. Please try another room");
		}
		else
		{
			Schedule newS = new Schedule(day, hour, minute, duration, r);
			sem.addSch(semID, newS);
		}
	}
	
	public void removeSchFromSem(String semID, String day, int hour, int minute, int duration, int roomNo, int buildingNo)
	{
		Room r = rooms.getRoom(roomNo, buildingNo);
		if (r.getRoom() == -1)
		{
			System.out.println("Error: no such room found in the system. Add the room to the system or check your data.");
		}
		else
		{
			Schedule newS = new Schedule(day, hour, minute, duration, r);
			sem.removeSch(semID, newS);
		}
	}
	
	public void getSch(String semID)
	{
		sem.show(semID);
	}
}
