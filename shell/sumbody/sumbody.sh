#!/bin/bash
cat << END
<html>
<head>
<meta charset="UTF-8">
</head>
<body>
<table border="1">
END
while read LINE
do
	MENOAPR=$(echo "$LINE" | cut -f1 -d,)
	SUMBODY=$(echo "$LINE" | cut -f2- -d, | tr , +| bc)
	echo "<tr><td>$MENOAPR</td><td>$SUMBODY</td></tr>"
done
cat << END
</table>
</body>
</html>
END
