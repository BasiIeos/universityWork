package main.java.ca.viu.csci331.instruction.model;

import java.util.*;

public class Rooms
{
	private LinkedList <Room> rooms = new LinkedList <Room> ();
	private final int cap;
	private int numberOfRooms;
	
	public Rooms(int c)
	{
		cap = c;
		numberOfRooms = 0;
	}
	
	public void add(Room newR)
	{
		if (numberOfRooms == cap)
		{
			System.out.print("Error: Rooms database is at it's capacity, please try again later\n");
		}
		else
		{
			boolean c = false;
			for (int i = 0; ((i < numberOfRooms) && (!c)); i++)
			{
				if ((newR.getRoom() == rooms.get(i).getRoom()) || (newR.getBuilding() == rooms.get(i).getBuilding()))
					c = true;
			}
			if (c)
				System.out.print("Error: this room is already in the database");
			else
			{
				rooms.add(newR);
				numberOfRooms++;
			}
		}
	}
	
	public void remove(Room r)
	{
		if (rooms.contains(r))
		{
			int i = rooms.indexOf(r);
			rooms.remove(i);
			numberOfRooms--;
		}
		else
		{
			System.out.println("Error: no such room found. Please check your data and try again\n");
		}
	}
	
	public void update(Room oldRoom, Room newRoom)
	{
		rooms.remove(oldRoom);
		rooms.add(newRoom);
	}
	
	public void showBuilding(int buildingNumber)
	{
		System.out.print("Rooms in building ");
		System.out.print(buildingNumber);
		System.out.println(":");
		for (int i = 0; i < numberOfRooms; i++)
		{
			if (rooms.get(i).getBuilding() == buildingNumber)
			{
				System.out.print(rooms.get(i).getRoom());
				System.out.print(" ");
			}
		}
		System.out.print("\n");
	}
	
	public void showCapacity(int cap)
	{
		System.out.print("Rooms woth capacity greater than or equal to ");
		System.out.print(cap);
		System.out.println(":");
		for (int i = 0; i < numberOfRooms; i++)
		{
			if (rooms.get(i).getCapacity() >= cap)
			{
				System.out.print(rooms.get(i).getRoom());
				System.out.print(" ");
				System.out.println(rooms.get(i).getBuilding());
			}
		}
	}
	
	public Room getRoom(int roomNo, int buildingNo)
	{
		Room r = new Room(-1, -1, -1);
		for (int i = 0; ((i < numberOfRooms) && (r.getRoom() == -1)); i++)
		{
			if ((rooms.get(i).getBuilding() == buildingNo) && (rooms.get(i).getRoom() == roomNo))
			{
				r = rooms.get(i);
			}
		}
		return r;
	}
	
	public LinkedList <Room> checkCap(int cap)
	{
		LinkedList <Room> ans = new LinkedList <Room>();
		for (int i = 0; i < numberOfRooms; i++)
		{
			if (rooms.get(i).getCapacity() >= cap)
				ans.add(rooms.get(i));
		}
		return ans;
	}
}
