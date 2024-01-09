# Introduction and General Sections in WebGoat
## Introduction 
This section helps you understand how the environment works and how you should navigate the webpage. The first two challenges allow you to test the mail client and the fake reset password.To solve the email challenge, it is sufficient to send an email to your address and wait for the unique code.To solve the password reset challenge, it is sufficient to inspect the content of the HTML page. Within the body, you will find the uniqueCode flag hardcoded.
## General
### HTTP Basics
**Question 3**It is sufficient to come back to the previous tab (Question 2) and inspect the page. We will see that the input section is wrapped into an HTML form with method="POST", hence the answer is **POST**.For what concerns the magic number, we have to inspect the current tab (Question 3) and we will see that a script with name="magic_num" and value=28 is present, hence the magic number is **28**.
### HTTP Proxies
**Question 5**After having setup the ZAP proxy on your system, follow the instructions of the exercise.It is sufficient to set up the breakpoint in the correct way (as explained in the guide) and click on "Submit" to produce a POST request. It will be intercepted by ZAP, and you can modify it according to the instructions:- Change the Method to GET- Add a header 'x-request-intercepted:true'- Remove the request body and instead send 'changeMe' as a query string parameter and set the value to 'Requests are tampered easily' (without the single quotes)
Then send the modified request, and you should get a successful message.

