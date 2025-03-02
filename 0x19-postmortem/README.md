Postmortem: Database Connection Failure in TripGwiji App

Issue Summary
Duration: September 18, 2024, 14:15 EAT - 15:05 EAT (50 minutes)
Impact: Users were unable to generate trips in the TripGwiji app. Approximately 85% of users experienced errors when submitting their trip preferences.

Root Cause: 
A misconfigured database connection pool caused a bottleneck, leading to exhaustion of available connections and failure to process requests.

Timeline
14:15 - Monitoring system alerted high API failure rates for trip generation.
14:18 - Engineers began investigating the backend logs.
14:25 - Assumption: Third-party API issue causing timeouts. Engineers tested API response times.
14:35 - Noticed repeated database connection errors in logs. Assumed database server was down.
14:40 - Database was reachable, but connection pool metrics showed exhaustion.
14:45 - Escalated to the database team for further analysis.
14:55 - Identified root cause: misconfigured connection pool settings limiting available connections.
15:00 - Adjusted connection pool settings and restarted backend services.
15:05 - System restored, and users could generate trips again.

Root Cause and Resolution
Root Cause
The database connection pool was misconfigured with a maximum connection limit set too low (default limit of 10 active connections). As the user load increased, all available connections were quickly exhausted, causing requests to fail when new connections could not be established.
Resolution
Increased the database connection pool size to 50 active connections.
Implemented connection timeout handling to recycle unused connections.
Restarted backend services to apply the new settings.

Corrective and Preventative Measures
Improvements Needed
Optimize database connection pool settings for scalability.
Implement more robust monitoring on database connection usage.
Improve alerting thresholds for database failures to detect issues earlier.

Conclusion: This outage highlighted the importance of proper database connection management and proactive monitoring. Moving forward, we will implement connection scaling, monitoring improvements, and documentation updates to mitigate similar issues in the future.

