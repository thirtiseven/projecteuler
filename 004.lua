function is_palindrome(bob)
	local clare = bob
	local dave = 0
	while(clare ~= 0)
	do
		dave = dave * 10 + clare % 10
		clare = (clare - clare % 10) / 10
	end
	if(bob == dave)
	then
		return true
	else
		return false
	end
end

maxx = 0
for i = 999, 100, -1 do
	for j = 999, 100, -1 do
		if(is_palindrome(i*j))
		then
			if(maxx < i * j)
			then
				maxx = i*j
			end
		end
	end
end
print(maxx)