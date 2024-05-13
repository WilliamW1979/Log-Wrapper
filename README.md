Log Wrapper<br><br>
<p>Usage of this wrapper is free to use, just give me credit for it if you use it. Enjoy to your hearts content and feel free to let me know if you have suggestions to upgrade it.</p>
<p>This log wrapper is simple to use and makes logging events easier. I got tired of rewriting code to make logs, so I made this to make my life easier.</p>
<p>If you are programming sockets, logging what you send and what you recieve helps with finding errors and problems you won't generally see using the debugger. If my program requires logging events like server, I will create a class for the general logging of events. A second class though I will create for debugging problem. I will use a define to enable a second logging class / file for the events that normal users would not need. For instance</p>
<pre>
  #ifdef DEBUGLOG
    Debug("Data to send out!");
  #endif
</pre>

<p>This way to disable the code, you just comment out (// in front) of the <pre>#define DEBUGLOG</pre> and you disable the code that helps you find errors without having to remove anything. A simple trick to help you know what data is going through sockets and anything else the debugger won't help you with.</p>
<p>Now this log wrapper doesn't have levels in it because I wrote it 10 to 15 years ago, it wasn't something I was thinking about at the time. I might add it later if people want it.</p>
<p>To use this, all you need to do is declare your variable, open it, and then start logging. Don't forget to close it when you are done.</p>
<pre>
  LOG Log("Log File.log");
  Log.open();

  ...

    Log.Log("Data to log");

  ...

    Log.close();
</pre>

<p>Now to go over all the functions and what they do.</p>
<pre>bool Open();</pre>
<p>This opens the file for writing. Returns true if it opens properly and false if something went wrong.</p>
<pre>void Close();</pre>
<p>This closes the file once you are done.</p>
<pre>bool Log(string, bool);</pre>
<p>This is your Log function which is the whole point of the class. the bool is for creating a new line, the default is true (creates a new line) and you don't need to use it if you are creating a new line.</p>
<pre>void SetFilename(string);</pre>
<p>This sets the filename for your log (Default is Log.txt").</p>
<pre>SetDateTime(bool Date, bool Time);</pre>
<p>This function tells the log whether you want to include a datestamp and/or a timestamp with each log.</p>
<pre>void SetMode(ios_base::openmode);</pre>
<p>This is for changing the mode of the file when opening it up (Default is std::ios::app for appending).</p>
<pre>void UseUTCTime();</pre>
<p>This function tells the class to use UTC time (Local is default).</p>
<pre>void UseLocalTime();</pre>
<p>This function tells the class to use local time (DEFAULT SETTING).</p>
<pre>void UseDayCutter(bool);</pre>
<p>This feature will slice the log file based on days. So each day, a new log file will be created with the date stamped in the file name at the end. (This is default).</p>
<pre>void UseSpaces(bool);</pre>
<p>This allows you to decide if you want to use spaces in the filename or an underscore '_' for old school DOS like filenames.</p>
<pre>void EraseFile();</pre>
<p> ***DANGER*** Use this function at your own risk because it will clear out the file leaving it empty. I would only use this for DEBUGGING purposes.</p>
<pre>void ClearFile();</pre>
<p> ***DANGER*** Use this function at your own risk because using it means the file is gone forever! This will completely delete the file. I would only use this for DEBUGGING purposes.</p><br><br>
<pre>
  William Glenn Ward
  Computer Programmer / Graphic Designer
  WilliamW1979@netscape.net
  programming since 1998
</pre>
