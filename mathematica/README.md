distance\_matrix: interactive demo for distance matrix visualizations

```
nPoint = 8; pt = RandomReal[{-1, 1}, {nPoint, 2}]; DynamicModule[{}, 
 GraphicsGrid[{{LocatorPane[Dynamic[pt], 
     Graphics[{Gray, Disk[]}, PlotRange -> 1, 
      ImageSize -> {400, 400}], 
     Appearance -> 
      Table[Style["\[FilledCircle]" h, Hue[h/nPoint]], {h, nPoint}]], 
    Dynamic@MatrixPlot[DistanceMatrix@pt, 
      ColorFunction -> ColorData["BlueGreenYellow"]], 
    Dynamic@ListPlot3D[
      Evaluate[ 
       Table[Norm[Part[pt, i] - Part[pt, j]], {i, Length@pt}, {j, 
         Length@pt}]], Mesh -> None, InterpolationOrder -> 3, 
      ColorFunction -> ColorData["BlueGreenYellow"], 
      PlotRange -> All]}}, ImageSize -> {1400, 600}]]
```
