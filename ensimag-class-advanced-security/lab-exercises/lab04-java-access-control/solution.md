# Solution for the lab exercise regarding java access control

## Using permissions in Java

Compile and run the program to see its output.

Test the security manager running environment with:

```bash
    java -Djava.security.manager GetProps
```

Output comparison:

| Information | Security Manager On | Security Manager Off |
| ----------- | ------------------- | -------------------- |
| os.name | v | v |
| java.version | v | v |
| user.home | x | v |
| java.home | x | v |

The program generates an exception when trying to read the user.home value. A **java.security.AccessControlException** is raised.
This happens because the program does not have the right priviledge to read such information (user.home and java.home).

Test the **examplepolicy** with the following command:
```bash
java -Djava.security.manager -Djava.security.policy=examplepolicy GetProps
```

In the policy there are both the "user.home" and "java.home" permission specification.

If you try to move the GetProps.class file into another directory the applied permission won't work. This is because the permissions are directory-specific so they apply only to the related directory.

## Calling a restricted method belonging to another class

Creating another class and calling the previous one from the new main still yields a correct result. However, by moving it into another folder, we lost the permission to the original variables.
