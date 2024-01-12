Access Control with Java
Download the required files from Moodle before starting.

1) Using permissions in Java
Look at the file GetProps.java which prints on the screen some systems and user defined environment
values.
- Compile it (javac GetProps.java) and run it (java GetProps) in the usual way.
- This program works well because, by default, local Java applications inherit all permissions allowed to
the current user. To better control the resource accesses made by untrusted code (e.g., not signed by a
trustable authority), a secure way is to run applications with a security manager:
java -Djava.security.manager GetProps
What happens? Why ?
- To fix this problem, a solution is to write an access control policy that tells which applications are allowed to dowhat.

An example of a security policy is given in the file examplepolicy.
Execute the following command now:
java -Djava.security.manager -Djava.security.policy=examplepolicy GetProps
What do you observe? Fix the remaining problem by extending the security policy file.
- Copy the GetProps.class file to another directory and run it from this directory. What do you observe?

2) Calling a restricted method belonging to another class
- Change the code of the previous example in order to split it into two files:
- - a file GetProps.java containing only one class GetProps, with a class constructor that prints all the
environment information, but without the main function;
- - a file Untrusted.java containing a single main function that calls the GetProps method (and imports
GetProps.*).
- Compile these two classes separately and run them:
javac GetProps.java
javac -cp . Untrusted.java
java -Djava.security.manager -Djava.security.policy=examplepolicy-cp . Untrusted
What do you observe?
- Move the Untrusted.class file to another directory and re-run the command (updating the class path option!).
Does it still work?

3) Enable privileges
- Have a look at the following web page:
https://docs.oracle.com/javase/7/docs/technotes/guides/security/doprivileged.html
to understand how some operations could be temporarily » granted to other classes.
- Use this technique to grant read access to user.home. How does it work now?
- Extend your code to have more than two method calls in the stack in order to see how the stackinspection mechanism works...
4) If you have time, you can proceed with this tutorial, which will tell you more about security-oriented features provided by the Java API!