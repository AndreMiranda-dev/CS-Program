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


CS-330 Comp Graphic and Visualization 02/25/2026


How do I approach designing software?
--I approach software design by starting with a clear conceptual model, breaking the system into modular components, and planning the structure before writing code. For this project, that meant identifying each object in the 3D scene, its geometry, transformations, and how it interacted with lighting and the camera.

What new design skills has your work on the project helped you to craft?
--I strengthened my ability to decompose complex visual objects into basic primitives and improved at designing reusable components such as shape classes, transformation utilities, and shader interactions.

What design process did you follow for your project work?
--I used an iterative, layered design process by first planning the overall scene, then breaking objects into shapes, then mapping transformations, and fianlly refining the design as I discovered better approaches during the process.

How could tactics from your design approach be applied in future work?
--Modular decomposition, incremental refinement, and documenting decisions can be applied to any future software project, helping maintain clarity and scalability.

How do I approach developing programs?
--I treat development as an iterative cycle of experimentation, testing, and refinement. Instead of building everything at once, I develop in small, verifiable steps then I test my work and refine as I go along.

What new development strategies did you use while working on your 3D scene?
--I adopted stronger separation of concerns, keeping rendering logic, transformations, and object definitions organized. I also relied heavily on incremental testing to validate each object before integrating it into the full scene.

How did iteration factor into your development?
--Iteration was the most important step. With each milestone built on the last, I continually revisited earlier decisions with new understanding, improving both structure and clarity.

How has your approach to developing code evolved throughout the milestones, which led you to the project’s completion?
--My approach shifted from simply making things work to making them clean, reusable, and scalable. By the final milestone, my codebase was more organized, my debugging was more efficient, and my understanding of transformations and rendering pipelines got stronger.

How can computer science help me in reaching my goals?
--Computer science gives me the tools to think systematically, solve complex problems, and build meaningful software skills that support both my academic and professional goals in SCRUM and as a Product Owner.

How do computational graphics and visualizations give you new knowledge and skills that can be applied in your future educational pathway?
--They deepen my understanding of geometry, transformations, shaders, and rendering pipelines, which are essential for graphics, simulation, and game development.

How do computational graphics and visualizations give you new knowledge and skills that can be applied in your future professional pathway?
--These skills translate directly into fields like game development, UI/UX visualization, simulation, VR, and data visualization. They also strengthen my ability to design thoughtfully, iterate effectively, and communicate technical decisions which are all valuable in any professional role.





---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------





CS-360 Mobile Architect & Programming


Briefly summarize the requirements and goals of the app you developed. What user needs was this app designed to address?
--The app was designed to help users manage an inventory of items efficiently and intuitively. Its core goal was to allow users to add items, update quantities, view their full inventory, and receive feedback when quantities reached zero. The app addressed user needs for organization, quick data entry, clear visibility of stored items, and simple navigation.

What screens and features were necessary to support user needs and produce a user-centered UI for the app? How did your UI designs keep users in mind? Why were your designs successful?
--The app required a login screen, a home dashboard, an inventory list screen, an item detail screen, and an add/edit item screen. Each screen was designed with clarity, minimalism, and accessibility in mind. Buttons were clearly labeled, navigation was consistent, and forms were simple to complete. The UI succeeded because it reduced cognitive load, followed mobile design best practices, and ensured that users could complete tasks with minimal steps.

How did you approach the process of coding your app? What techniques or strategies did you use? How could those techniques or strategies be applied in the future?
--I approached coding by breaking the app into small, manageable components and implementing one feature at a time. I used modularization, consistent naming conventions, and incremental testing to keep the codebase organized. These strategies can be applied to any future project because they improve maintainability, reduce bugs, and make it easier to scale or modify features.

How did you test to ensure your code was functional? Why is this process important, and what did it reveal?
--I tested the app by running it frequently on the emulator, checking each screen transition, validating form inputs, and verifying database operations. This process is important because it catches issues early and ensures the app behaves as expected. Testing revealed small logic errors, UI alignment issues, and data handling mistakes that were easy to fix once identified.

Consider the full app design and development process from initial planning to finalization. Where did you have to innovate to overcome a challenge?
--One challenge required creativity when connecting the UI to the database logic. Ensuring that updates, deletions, and inserts were reflected instantly in the UI required careful handling of adapters and lifecycle events. I had to rethink how data flowed through the app and adjust my architecture to keep everything synchronized.

In what specific component of your mobile app were you particularly successful in demonstrating your knowledge, skills, and experience?
--The inventory list and item detail components were especially strong. They demonstrated my ability to design a clean UI, implement database backed functionality, and create a smooth user experience. These components showed my understanding of a user centered design language, mobile architecture, and practical Android development.





---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------






CS-340 Client/Server Development

How do you write programs that are maintainable, readable, and adaptable? Especially consider your work on the CRUD Python module from Project One, which you used to connect the dashboard widgets to the database in Project Two. What were the advantages of working in this way? How else could you use this CRUD Python module in the future?
--Writing programs that remain maintainable, readable, and adaptable over time requires designing each component with clarity and separation of responsibility. When developing the CRUD Python module, the goal was to create a single, consistent interface for all database interactions so that the dashboard could rely on it without needing to understand the underlying database structure. This approach made the overall system easier to extend, because any future changes to the database or data model would only require updates to the CRUD module rather than rewriting the dashboard logic. Working in this way also reduced duplication, improved reliability, and made the code easier to test and debug. The same CRUD module could be reused in future projects as a shared data access layer, a foundation for an API service, or a template for other dashboards that need structured and predictable database communication.

How do you approach a problem as a computer scientist? Consider how you approached the database or dashboard requirements that Grazioso Salvare requested. How did your approach to this project differ from previous assignments in other courses? What techniques or strategies would you use in the future to create databases to meet other client requests?
--I approach problems by breaking down the requirements into smaller, logical components and understanding the underlying purpose behind each feature. When analyzing the database and dashboard needs for Grazioso Salvare, the first step was to understand how the organization intended to use the data and what decisions the dashboard needed to support. This project differed from other earlier coursework because it required thinking about the system as a whole rather than completing isolated tasks. I had to make sure that the database structure, CRUD operations, and dashboard interface all worked together seamlessly. Moving forward, techniques such as careful schema design, modular code organization, early prototyping, and iterative refinement will continue to be essential when creating databases for future clients, ensuring that the final product is both functional and adaptable to changing requirements.

What do computer scientists do, and why does it matter? How would your work on this type of project help a company, like Grazioso Salvare, to do their work better?
--Computer scientists create systems that transform raw information into meaningful, actionable insights, and this work matters because organizations rely on accurate data to operate effectively. In a project like the one for Grazioso Salvare, the ability to organize, filter, and visualize animal records directly supports the organization’s mission by helping staff make faster and more informed decisions. A well‑designed dashboard reduces manual effort, minimizes errors, and allows the team to focus more on their core work rather than sorting through spreadsheets or inconsistent data sources. By building tools that streamline operations and improve access to information, computer scientists enable companies to work more efficiently, respond more quickly to real world needs, and ultimately achieve better outcomes.




---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




CS-370 Current/Emerging Trends



Briefly explain the work that you did on this project: What code were you given? What code did you create yourself?
--I was given the environment, experience replay classes, helper functions, and the model architecture, and I created the full deep Q‑learning loop including action selection, replay memory usage, model training, and target network updates.

What do computer scientists do and why does it matter?
--Computer scientists design systems that solve real world problems through computation, which matters because their solutions drive innovation, efficiency, and automation across every industry.

How do I approach a problem as a computer scientist?
--I approach problems by breaking them into smaller components, analyzing constraints, designing algorithms, and iterating through testing and refinement.

What are my ethical responsibilities to the end user and the organization?
--My ethical responsibilities include ensuring accuracy, safety, transparency, and fairness in the systems I build while protecting user data and aligning with organizational standards.




---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




CS-350 Emerging Sys Arch and Tech



Milestone 3 Summary:
--Milestone Three focused on implementing button driven input and integrating it with a Morse‑code state machine that controlled LED blinking, timing delays, and message selection. The project required handling single‑press and double‑press logic, updating the active message, and ensuring that the LED transmission loop ran concurrently without blocking the main program. I also created a detailed state machine diagram that mapped out every transition between dot, dash, pauses, and message‑selection states. This milestone demonstrated how to combine real‑time input handling with time sensitive output in an embedded environment.

What did you do particularly well?
--I did particularly well in designing a clean and predictable state machine that controlled every aspect of the Morse‑code output. Each state returned to a stable off state, which made the system easy to reason about and prevented conflicting LED behavior. I also handled button input cleanly by separating single‑press and double‑press logic, allowing the user to switch between messages without interrupting the LED transmission thread. The clarity of the diagram and the responsiveness of the system were strong points of my milestone.

Where could you improve?
--One area for improvement would be modularizing the code further so that the LED logic, button logic, and message‑handling logic are more isolated from each other. While the system works well, separating these responsibilities into dedicated modules or classes would make the program easier to maintain and extend. I could also improve error handling, especially around debouncing edge cases or handling unexpected timing overlaps between button presses and LED output. Strengthening these areas would make the system more robust and scalable.

What tools and/or resources are you adding to your support network?
--Milestone three added several useful tools and resources to my workflow, including Python’s threading library for concurrent execution, GPIOZero for clean button and LED handling, and timing utilities for managing precise delays. I also relied heavily on state machine design principles and diagramming tools to visualize transitions clearly. These resources will continue to support future embedded projects where concurrency, timing, and hardware interaction are essential.

What skills from this project will be particularly transferable to other projects and/or course work?
--The most transferable skills from this milestone include designing finite state machines, managing concurrency through threading, and handling real‑time hardware input without blocking system behavior. These skills apply broadly to embedded systems, IoT development, robotics, and any software that requires event‑driven logic. Additionally, the ability to translate hardware behavior into clear diagrams and structured logic will be valuable in both academic and professional settings.

How did you make this project maintainable, readable, and adaptable?
--I made the project maintainable by structuring the state machine so that every action returned to a predictable off state, which simplified transitions and reduced the chance of inconsistent behavior. The code was written with clear naming conventions, comments explaining timing values, and logical separation between button handling and LED output. The state machine diagram also serves as documentation that makes the system easy to understand and modify. These choices ensure that the project can be extended with new messages, additional input methods, or more complex timing rules without major restructuring.





Final Project Summary:
--This project involved building a functional thermostat prototype that could read temperature and humidity, respond to user input, display system information, and simulate cloud communication. The goal was to create a low‑level embedded system that met SysTec’s requirements before moving into full IoT development. By integrating the AHT20 sensor, LEDs, buttons, an LCD, and UART output into a finite state machine, the system demonstrated how a modern thermostat could manage environmental data and user interactions in real time. The project solved the problem of producing a dependable, hardware driven prototype that could later be expanded with Wi-Fi and cloud services.

What did you do particularly well?
--I executed the finite state machine design especially well, ensuring that each system mode, OFF, HEAT, and COOL, behaved predictably and followed clear transition rules. The timing logic for the LCD, the LED behavior tied to temperature thresholds, and the interrupt‑driven button handling all worked smoothly together without blocking or lag. I also communicated the system’s behavior clearly through both the written report and the state machine diagram, which made the architecture easy to understand and evaluate. This combination of clean logic, responsive input handling, and strong documentation is one of the strongest aspects of the project.

Where could you improve?
--If I were to improve the project, I would focus on making the codebase more modular and scalable. Several parts of the system, such as LED control, display updates, and UART formatting, could be separated into dedicated modules or classes to reduce repetition and improve clarity. I would also add more robust error handling for sensor failures or unexpected input conditions, which would make the system more resilient in real‑world scenarios. These improvements would make the project easier to maintain and better prepared for future features like Wi-Fi connectivity and cloud integration.

What tools and/or resources are you adding to your support network?
--Throughout this project, I added several valuable tools and resources to my development workflow, including the GPIOZero and smbus libraries for hardware interfacing, Raspberry Pi documentation for UART, I2C, and GPIO, and datasheets for the AHT20 sensor and LCD. I also expanded my familiarity with Microchip and NXP architecture documentation while evaluating production‑ready hardware options. These resources form a solid foundation for future embedded and IoT projects, giving me reliable references for both hardware capabilities and software integration techniques.

What skills from this project will be particularly transferable to other projects and/or course work?
--The most transferable skills from this project include designing and implementing finite state machines, writing interface software for hardware components, and managing interrupt‑driven input. These skills apply broadly across embedded systems, IoT development, and even higher‑level software engineering where structured logic and event‑driven behavior are essential. Additionally, evaluating hardware architecture based on business requirements strengthened my ability to make informed technical recommendations, a skill that is valuable in both academic and professional settings.

How did you make this project maintainable, readable, and adaptable?
--I made the project maintainable and readable by organizing the system around a clear finite state machine and writing code with descriptive variable names, consistent structure, and meaningful comments. The logic for sensor reading, display updates, LED behavior, and UART output was kept clean and predictable, making it easy for someone else to follow. The UART format and state machine diagram also serve as documentation that supports future expansion, ensuring the system can be adapted for cloud connectivity or additional features without major restructuring.





---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

