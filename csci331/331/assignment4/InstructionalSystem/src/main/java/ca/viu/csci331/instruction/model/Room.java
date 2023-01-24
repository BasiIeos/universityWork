package main.java.ca.viu.csci331.instruction.model;

public class Room
{
	private int roomNumber;
	private int buildingNumber;
	private int capacity;
	
	public Room()
	{
	}
	
	public Room(int roomN, int buildingN, int cap)
	{
		roomNumber = roomN;
		buildingNumber = buildingN;
		capacity = cap;
	}
	
	public void show()
	{
		System.out.print("Room number: ");
		System.out.println(roomNumber);
		System.out.print("Building number: ");
		System.out.println(buildingNumber);
		System.out.print("Capacity: ");
		System.out.println(capacity);
	}
	
	public int getRoom()
	{
		return roomNumber;
	}
	
	public int getBuilding()
	{
		return buildingNumber;
	}
	
	public void setRoom(int newRoom)
	{
		roomNumber = newRoom;
	}
	
	public void setBuilding(int newBuilding)
	{
		buildingNumber = newBuilding;
	}
	
	public int getCapacity()
	{
		return capacity;
	}
	
	public void setCapacity(int newCap)
	{
		capacity = newCap;
	}
}
