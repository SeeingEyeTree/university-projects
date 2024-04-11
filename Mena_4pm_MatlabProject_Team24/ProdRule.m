% Megan Baker, Sarah Ginck, and Dennis Ephraim --> Team 24

function re=ProdRule(one,two)
    %takes drive
    done=OneLine(decompose(one));
    dtwo=OneLine(decompose(two));
    %formats
    re=['(',one,')*(',dtwo,')+(',two,')*',done];

end