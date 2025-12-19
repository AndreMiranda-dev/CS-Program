# CS-Program

CS-250 Software Development Lifecycle 6/29/2025

How do I interpret user needs and implement them into a program? How does creating “user stories” help with this?

--Interpreting user needs is essential to bring value to your stakeholders. Asking questions, observing the user needs, and reiterating needs in a clear and simplistic way will allow you to be able to fully understand the user needs and be able to deliver valuable products. Once you understand the requirements, user stories act like a bridge from what the users need and want to the developers who will be working on these requirements.


How do I approach developing programs? What Agile processes do I hope to incorporate into my future development work?

--Scrum and agile has been a huge help in constant delivery of value to our stakeholder at my current position. As a Product Owner it is essential that I am able to communicate with my users in a way they can understand and be able to translate their needs to the developers. Sprint reviews are a big part of that, and therefore keeping a good line of communication with my users is essential!


What does it mean to be a good team member in software development?

--A good team member in software development is one who helps each other accomblish the vision and goal, one that is transparent with the team and communicates blockers quickly, and one that is able to adapt to changing requirements.



---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

CS-210 Programing Languages 6/29/2025

Summarize the project and what problem it was solving.

--Project 3/CornerGrocer is a software that allows you to read from a file all of the different items in the grocery store and counts the frequency of each. It then allows you to choice from serveral choices on how you would like to view the results or what you would like to view from the file.


What did you do particularly well?

--I think I did a great job on the switch case and the menu. It looks nice and is easy to understand.


Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

--I would love to add an option to the menu were it could emulate a checkout scenario where someone is scanning different items in there cart and have that deduct from the available items. This would be in text game style format. 


Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

--Every time I came to a pump in the road or an issue with my code it always helped me to step away or work on something different and then coming back to the problem with fresh eyes and a clear mind. This allowed me to better understand the problems or blockers before continuing with my solution.


What skills from this project will be particularly transferable to other projects or course work?

--Being able to write clear and understandable code is a great transferable skill that I will take not only from this project, but from the class overall. Most of my job will be review other's code so it would great when others can understand the code that is written.


How did you make this program maintainable, readable, and adaptable?

--Modularity is a great way of keeping your code maintanable, readable, and adaptable. It is also easier to understand and to be able to solve issues better when you take a more modular approach to your development!



---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

CS-230 Operating Platforms 8/21/2025


Briefly summarize The Gaming Room client and their software requirements. Who was the client? What type of software did they want you to design?

--The Gaming Room is a startup client aiming to expand their successful trivia game, "Draw It or Lose It," across multiple platforms including Android, iOS, Windows, and web. They want a scalable, modular game engine that could support multiplayer sessions, maintain game state across devices, and ensure consistent performance regardless of platform.



What did you do particularly well in developing this documentation?

--I clearly articulated the system architecture and platform constraints by breaking down the design into modular components like game logic, UI rendering, and session management. I also included a diagram and my recommendations to make sure the client had the best foundations for their trivia game.



What about the process of working through a design document did you find helpful when developing the code?

--The design document forced me to think through edge cases and dependencies before touching a line of code. It helped me anticipate integration challenges, especially around platform-specific APIs and session persistence. Having a well-defined blueprint makes implementation smoother and reduced rework.



If you could choose one part of your work on these documents to revise, what would you pick? How would you improve it?

--I’d revise the section on error handling and recovery. Initially, it was too generic and didn’t account for platform-specific failure modes. I’d improve it by adding detailed flowcharts for exception handling and fallback mechanisms tailored to each platform.



How did you interpret the user’s needs and implement them into your software design? Why is it so important to consider the user’s needs when designing?

--I translated user needs, specifically the fast load times, intuitive gameplay, and cross-device continuity, into technical requirements such as lightweight assets, responsive UI, and cloud-based session storage. Considering user needs ensures the software is not just functional but also enjoyable and accessible, which directly impacts the value, adoption, and retention.



How did you approach designing software? What techniques or strategies would you use in the future to analyze and design a similar software application?

--I used a layered architecture approach, starting with core game logic and building outward to platform-specific interfaces. I also applied use-case modeling and user stories to guide feature prioritization. In the future, I’d incorporate more automated testing frameworks and CI/CD pipelines early in the design phase to support faster iteration and deployment.



---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

CS-255 System Analysis and Design 8/21/2025

Briefly summarize the DriverPass project. Who was the client? What type of system did they want you to design?

--DriverPass is a client focused on helping users pass their driver’s license exams through a combination of online learning modules, scheduling tools, and practice tests. They want a comprehensive web-based system that could manage user accounts, track progress, and integrate with DMV scheduling systems to streamline the testing process.



What did you do particularly well?

--I created a clear separation between user-facing features and administrative tools, which made the system easier to maintain and scale. I also documented the data flow and user interactions thoroughly, which helped align the development team and stakeholders around a shared vision.



If you could choose one part of your work on these documents to revise, what would you pick? How would you improve it?

--I’d revise the integration plan with external DMV systems. Initially, it lacked detail on authentication protocols and data validation. I’d improve it by specifying API endpoints, expected response formats, and fallback procedures in case of outages.



How did you interpret the user’s needs and implement them into your system design? Why is it so important to consider the user’s needs when designing?

--I focused on accessibility, simplicity, and progress tracking which are the key concerns for users preparing for the exam. Considering user needs ensures the system is not just functional but actually supports the user’s goals, which adds value, drives engagement, and project success.



How do you approach designing software? What techniques or strategies would you use in the future to analyze and design a system?

--I start with user stories and use case diagrams to understand the core workflows. Then I build a modular architecture that separates features and allows for future expansion. In future projects, I’d incorporate more usability testing early on and use prototyping tools to validate any design assumption before full development.



---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

CS-305 Software Security 10/23/2025


Briefly summarize your client, Artemis Financial, and its software requirements. Who was the client? What issue did the company want you to address?

--The client, Artemis Financial, is a U.S.-based financial consulting and investment firm that handles highly sensitive client data, including PII, biometric markers, account credentials, and proprietary financial strategies. Their software requirements centered on secure communication, regulatory compliance (GLBA, SOX, PCI DSS), and resilience against cyber threats. My task was to assess their software application for vulnerabilities and recommend mitigation strategies to strengthen security posture.




What did you do well when you found your client’s software security vulnerabilities? Why is it important to code securely? What value does software security add to a company’s overall well-being?

--I conducted a thorough manual review and static testing of the codebase, identifying critical vulnerabilities across input validation, API exposure, cryptographic practices, client-server communication, and error handling. I provided targeted recommendations for each issue, such as enforcing HTTPS, validating user input, and upgrading vulnerable dependencies. This precision ensured that each risk was addressed with a practical, actionable fix. Secure coding is essential to prevent data breaches, financial fraud, and reputational damage. For Artemis, software security directly impacts client trust, regulatory compliance, and operational continuity. A secure application reduces attack points, ensures data integrity, and supports long-term scalability.



Which part of the vulnerability assessment was challenging or helpful to you?

--The most challenging part was identifying hidden risks in API exposure and cryptographic misconfigurations, especially hardcoded credentials and unsecured endpoints. The most helpful aspect was the structured vulnerability assessment flow diagram because it guided my review and ensured I didn’t overlook key areas like encapsulation and code quality.



How did you increase layers of security? In the future, what would you use to assess vulnerabilities and decide which mitigation techniques to use?

--I implemented multiple layers of defense by validating all user inputs to prevent injection and logic errors. I enforced HTTPS and SSL/TLS for secure data transmission and applied role-based access control to sensitive methods. I also refactored code to encapsulate sensitive fields and remove redundant entry points and then upgraded third-party libraries to patch known CVEs. In future projects, I would use automated tools like OWASP Dependency-Check, SonarQube, and Snyk for static analysis, combined with manual code reviews and threat modeling. I’d also apply CVE tracking and use secure development lifecycle practices to guide mitigation decisions.




How did you make certain the code and software application were functional and secure? After refactoring the code, how did you check to see whether you introduced new vulnerabilities?

--After refactoring, I reran static tests and manually verified that all endpoints behaved as expected. I checked for regressions, validated input and output flows, and confirmed that no new vulnerabilities were introduced. I also ensured that error handling was consistent and secure.



What resources, tools, or coding practices did you use that might be helpful in future assignments or tasks?

--In future projects, I plan to use the OWASP Top 10 and CVE databases to stay informed about common and emerging vulnerabilities, adhering to secure coding conventions such as proper naming, access control, and input validation, and maintaining disciplined dependency management and upgrade workflows. I will also continue using secrets management tools to handle credentials securely and implement structured error logging and exception handling to ensure both security and maintainability.



Employers sometimes ask for examples of work that you have successfully completed to show your skills, knowledge, and experience. What might you show future employers from this assignment?

--To demonstrate my skills and experience to future employers, I would present my vulnerability assessment report as evidence of my ability to identify and analyze software security risks. I would also share before and after code samples to highlight my secure refactoring capabilities, include the dependency-check output to showcase my proficiency with static analysis tools, and provide my mitigation plan to illustrate my strategic thinking and understanding of regulatory compliance in secure software development.





---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

CS-320 Software Test, Automation QA 12/18/2025


How can I ensure that my code, program, or software is functional and secure?

--I ensure functionality through rigorous unit testing, integration testing, and continuous validation against requirements. To maintain security, I follow best practices such as input validation, secure coding standards, and regular code reviews. Automated tools help detect vulnerabilities early, while version control and rollback mechanisms safeguard against deployment risks. Together, these practices create reliable, maintainable, and secure software.



How do I interpret user needs and incorporate them into a program?

--I begin by gathering clear requirements through communication, documentation, and user stories. I translate these needs into functional specifications and prioritize features based on impact and feasibility. Iterative development and feedback loops allow me to refine the program as user expectations evolve. This ensures the final product aligns with real-world use cases and delivers meaningful value.



How do I approach designing software?

--I approach design with a structured methodology: defining requirements, modeling system architecture, and planning modular components. I emphasize scalability, maintainability, and clarity by using design patterns and adhering to coding standards. Prototyping and diagramming help visualize workflows before implementation. This disciplined approach ensures the software is robust, adaptable, and easy to extend in the future.




---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


CS-300 DSA: Analysis and Design 12/18/2025


What was the problem you were solving in the projects for this course?

--The core problem was designing a system to store, validate, and retrieve course information efficiently. The challenge wasn’t just reading data from a file, it was ensuring that prerequisites were valid, searches were fast, and the course list could be presented in a sorted, user-friendly way. In short, the problem was about choosing the right data structure to balance correctness, performance, and usability.



How did you approach the problem? Consider why data structures are important to understand.

--I approached the problem by implementing three different data structures/vector, hash table, and binary search tree and analyzing their trade-offs. Data structures are fundamental because they dictate how quickly and efficiently information can be stored, searched, and organized. By comparing runtime complexities and practical usability, I was able to see how each structure shaped the program’s behavior and why the BST ultimately offered the best balance of ordered output and efficient searching.



How did you overcome any roadblocks you encountered while going through the activities or project?

--One major roadblock was handling invalid or missing prerequisites. To overcome this, I added validation checks during the load process, ensuring that every prerequisite referenced an existing course. Another challenge was managing sorting in the hash table implementation, which required extracting and ordering keys separately. By breaking these issues into smaller steps and testing incrementally, I was able to validate correctness before optimizing performance.



How has your work on this project expanded your approach to designing software and developing programs?

--This project reinforced the importance of analyzing requirements before committing to an implementation. It showed me that software design isn’t just about “making it work” it’s about choosing structures and algorithms that align with the problem’s constraints. I now think more critically about efficiency, scalability, and how design decisions affect both the user experience and long-term maintainability



How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?

--I’ve become more deliberate about structuring code with clarity and modularity. Using pseudocode and separating concerns (loading, validation, searching, printing) made the program easier to read and extend. I also learned to anticipate future needs like adding new search features or handling larger datasets by writing functions that are adaptable rather than rigid. This project has pushed me toward writing code that is not only correct but also clean, maintainable, and ready to evolve with new requirements.






---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------









