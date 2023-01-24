package main.java.ca.viu.csci331.instruction.persistence.admission;

import main.java.viu.csci331.instruction.services.admission.*;
import java.io.*;

public class PersistenceOfAdmission
{
	public void write(Admission a) throws IOException
	{
		a.write("storage.txt");
	}
}
