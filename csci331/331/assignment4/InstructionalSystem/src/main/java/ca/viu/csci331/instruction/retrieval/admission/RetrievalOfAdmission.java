package main.java.ca.viu.csci331.instruction.retrieval.admission;

import main.java.viu.csci331.instruction.services.admission.*;
import java.io.*;

public class RetrievalOfAdmission
{
	public void write(Admission a) throws IOException
	{
		a.read("storage.txt");
	}
}
