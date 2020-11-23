function wait(secs)
    local previousUptime = os.clock();
    local waitLoop = true
    while waitLoop == true do
        local currentUptime = os.clock();
        if currentUptime > previousUptime + secs then
            waitLoop = false
        end
    end
end

function about()
    print("Engineish Prealpha Release 11232020")
    print("The open Engine(ish)")
end

closureLoop();
about();