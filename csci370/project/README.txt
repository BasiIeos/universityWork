README.txt for Project for CSCI370 by Vasily Kontorer
I tend to forget about my deadlines, so I created this application for you not to have the sma problem! Meet deadline manager application: the easiest way to manage deadlines!
This application can save your courses, teachers and the deadlines themselves! You can look up a particular course, teacher or deadline! You can search for incomplete deadlines or all of them! You can complete a deadline and have the application congratulate you! You can search for incomplete deadlines for a specific course!
This is the database schema for this application:
projCourses(cno primary, credits, title);
projInstructors(insid primary, name, email, website);
Teaching(cno references projCourses, insid references projInstructors, sno);
Deadlines(did primary, cno references projCourses, name, worth, time, submit, status);
Sample Data:

projCourses:
cno: CSCI370
title: Introduction to Database Systems
credits: 3

projInstructors:
insid: (it's random, because I don't know Huizhu's insid) 1234567
name: Huizhu Liu
email: huizhu.liu@viu.ca
website: cdci.viu.ca/~liuh

projTeaching:
cno: CSCI370
insid: 1234567
sno: S19S02

projDeadlines:
did: 1
cno: CSCI370
name: Project
time: 2019.04.12 16:00
submit: ~liuh/bin/submit 370 project .
status: incomplete

I tested the application according to sample data, everything works.
