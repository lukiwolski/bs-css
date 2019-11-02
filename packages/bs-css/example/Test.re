let text = React.string;

Css.insertRule(
  ".raw-css { display:block; background-color: green; width: 50px; height: 50px; }",
);

let fontItem =
  Css.[
    marginLeft(px(10)),
    paddingRight(px(10)),
    borderRight(px(1), solid, black),
  ];

let spin =
  Css.(
    keyframes([
      (0, [transform(rotate(deg(0.)))]),
      (100, [transform(rotate(deg(360.)))]),
    ])
  );

let scaleAnimation =
  Css.(
    keyframes([
      (0, [transform(scale(0.3, 0.3))]),
      (100, [transform(scale(1.0, 1.0))]),
    ])
  );

let redBox =
  Css.[
    background(red),
    borderBottom(px(5), solid, black),
    width(px(50)),
    height(px(50)),
    margin(px(10)),
  ];

let miniBox =
  Css.[
    border(px(2), solid, black),
    width(px(15)),
    height(px(15)),
    margin(px(1)),
  ];

// https://github.com/SentiaAnalytics/bs-css/issues/86
let mergedStyles =
  Css.(
    merge([
      style([padding(px(0)), fontSize(px(1))]),
      style([padding(px(20)), fontSize(px(24)), color(blue)]),
      style([media("(max-width: 768px)", [padding(px(10))])]),
      style([
        media("(max-width: 768px)", [fontSize(px(16)), color(red)]),
      ]),
    ])
  );

let differentHeightLengths =
  Css.(
    [|
      cm(1.),
      em(1.2),
      ex(1.2),
      mm(10.),
      pct(50.),
      pt(14),
      px(20),
      rem(2.0),
      vh(1.),
      vw(1.0),
      vmax(1.0),
      vmin(1.0),
      zero,
    |]
    |> Array.map(x => {
         let className = style(redBox @ [height(x)]);
         <div className key=className />;
       })
  )
  ->React.array;

[@react.component]
let make = () =>
  <div className=Css.(style([background(hex("f5f5f5"))]))>
    <Section name="angles">
      <div
        className=Css.(style(redBox @ [transform(rotate(deg(45.)))]))
      />
      <div
        className=Css.(style(redBox @ [transform(rotate(rad(3.1415)))]))
      />
      <div
        className=Css.(style(redBox @ [transform(rotate(grad(50.)))]))
      />
      <div
        className=Css.(
          style(redBox @ [transform(rotate(turn(1. /. 3.)))])
        )
      />
    </Section>
    <Section name="colors">
      <div className=Css.(style(redBox @ [background(red)])) />
      <div className=Css.(style(redBox @ [background(rgb(255, 0, 0))])) />
      <div
        className=Css.(style(redBox @ [background(rgba(255, 0, 0, 0.5))]))
      />
      <div
        className=Css.(
          style(redBox @ [background(hsl(deg(255.), 100., 50.))])
        )
      />
      <div
        className=Css.(
          style(
            redBox @ [background(hsla(deg(255.), 100., 50., `num(0.5)))],
          )
        )
      />
      <div className=Css.(style(redBox @ [background(hex("FF0000"))])) />
      <div className=Css.(style(redBox @ [background(transparent)])) />
      <div
        className=Css.(
          style(redBox @ [background(currentColor), color(blue)])
        )
      />
    </Section>
    <Section name="Named colors">
      {React.array(
         Css.(
           [|
             aliceblue,
             antiquewhite,
             aqua,
             aquamarine,
             azure,
             beige,
             bisque,
             black,
             blanchedalmond,
             blue,
             blueviolet,
             brown,
             burlywood,
             cadetblue,
             chartreuse,
             chocolate,
             coral,
             cornflowerblue,
             cornsilk,
             crimson,
             cyan,
             darkblue,
             darkcyan,
             darkgoldenrod,
             darkgray,
             darkgreen,
             darkgrey,
             darkkhaki,
             darkmagenta,
             darkolivegreen,
             darkorange,
             darkorchid,
             darkred,
             darksalmon,
             darkseagreen,
             darkslateblue,
             darkslategray,
             darkslategrey,
             darkturquoise,
             darkviolet,
             deeppink,
             deepskyblue,
             dimgray,
             dimgrey,
             dodgerblue,
             firebrick,
             floralwhite,
             forestgreen,
             fuchsia,
             gainsboro,
             ghostwhite,
             gold,
             goldenrod,
             gray,
             green,
             greenyellow,
             grey,
             honeydew,
             hotpink,
             indianred,
             indigo,
             ivory,
             khaki,
             lavender,
             lavenderblush,
             lawngreen,
             lemonchiffon,
             lightblue,
             lightcoral,
             lightcyan,
             lightgoldenrodyellow,
             lightgray,
             lightgreen,
             lightgrey,
             lightpink,
             lightsalmon,
             lightseagreen,
             lightskyblue,
             lightslategray,
             lightslategrey,
             lightsteelblue,
             lightyellow,
             lime,
             limegreen,
             linen,
             magenta,
             maroon,
             mediumaquamarine,
             mediumblue,
             mediumorchid,
             mediumpurple,
             mediumseagreen,
             mediumslateblue,
             mediumspringgreen,
             mediumturquoise,
             mediumvioletred,
             midnightblue,
             mintcream,
             mistyrose,
             moccasin,
             navajowhite,
             navy,
             oldlace,
             olive,
             olivedrab,
             orange,
             orangered,
             orchid,
             palegoldenrod,
             palegreen,
             paleturquoise,
             palevioletred,
             papayawhip,
             peachpuff,
             peru,
             pink,
             plum,
             powderblue,
             purple,
             rebeccapurple,
             red,
             rosybrown,
             royalblue,
             saddlebrown,
             salmon,
             sandybrown,
             seagreen,
             seashell,
             sienna,
             silver,
             skyblue,
             slateblue,
             slategray,
             slategrey,
             snow,
             springgreen,
             steelblue,
             tan,
             teal,
             thistle,
             tomato,
             transparent,
             turquoise,
             violet,
             wheat,
             white,
             whitesmoke,
             yellow,
             yellowgreen,
           |]
         )
         ->Belt.Array.map(c =>
             <div className=Css.(style([background(c), ...miniBox])) />
           ),
       )}
    </Section>
    <Section name="gradients">
      <div
        className=Css.(
          style(
            redBox
            @ [
              background(
                linearGradient(
                  deg(45.),
                  [(zero, red), (pct(100.), blue)],
                ),
              ),
            ],
          )
        )
      />
      <div
        className=Css.(
          style(
            redBox
            @ [
              background(
                repeatingLinearGradient(
                  deg(45.),
                  [(zero, red), (pct(10.), blue)],
                ),
              ),
            ],
          )
        )
      />
      <div
        className=Css.(
          style(
            redBox
            @ [
              background(
                radialGradient([(zero, red), (pct(100.), blue)]),
              ),
            ],
          )
        )
      />
      <div
        className=Css.(
          style(
            redBox
            @ [
              background(
                repeatingRadialGradient([(zero, red), (pct(10.), blue)]),
              ),
            ],
          )
        )
      />
    </Section>
    <Section name="lengths">
      <div
        className=Css.(
          style(
            redBox
            @ [
              height(ch(1.2)),
              width(px(10)),
              maxHeight(pct(50.)),
              maxWidth(pct(100.)),
            ],
          )
        )
      />
      differentHeightLengths
    </Section>
    <Section name="calc">
      <div
        className=Css.(style(redBox @ [height(Calc.(pt(14) - px(10)))]))
      />
      <div
        className=Css.(style(redBox @ [height(Calc.(cm(0.2) + mm(10.)))]))
      />
    </Section>
    <Section name="display">
      <div className=Css.(style(redBox @ [display(block)])) />
      <div className=Css.(style(redBox @ [display(inline)])) />
      <div className=Css.(style(redBox @ [display(inlineBlock)])) />
      <div className=Css.(style(redBox @ [display(none)])) />
      <div className=Css.(style(redBox @ [display(flexBox)])) />
    </Section>
    <Section name="position">
      <div
        className=Css.(
          style(
            redBox
            @ [
              position(absolute),
              top(zero),
              left(zero),
              right(zero),
              bottom(zero),
            ],
          )
        )
      />
      <div className=Css.(style(redBox @ [position(relative)])) />
      <div
        className=Css.(
          style(
            redBox @ [position(fixed), bottom(px(10)), right(px(10))],
          )
        )
      />
      <div className=Css.(style(redBox @ [position(static)])) />
      <div className=Css.(style(redBox @ [position(sticky)])) />
    </Section>
    <Section name="Padding & Margin">
      <div
        className=Css.(style(redBox @ [padding(px(10)), margin(px(10))]))
      />
      <div
        className=Css.(
          style(
            redBox
            @ [
              paddingLeft(px(10)),
              paddingRight(px(10)),
              paddingTop(px(10)),
              paddingBottom(px(10)),
              marginLeft(px(10)),
              marginRight(px(10)),
              marginTop(px(10)),
              marginBottom(px(10)),
            ],
          )
        )
      />
      <div
        className=Css.(
          style(
            redBox
            @ [
              padding2(~v=px(10), ~h=px(20)),
              margin2(~v=px(10), ~h=px(20)),
            ],
          )
        )
      />
      <div
        className=Css.(
          style(
            redBox
            @ [
              padding3(~top=px(10), ~h=px(20), ~bottom=px(1)),
              margin3(~top=px(10), ~h=px(20), ~bottom=px(2)),
            ],
          )
        )
      />
      <div
        className=Css.(
          style(
            redBox
            @ [
              padding4(
                ~top=px(10),
                ~bottom=px(1),
                ~left=px(5),
                ~right=px(15),
              ),
              margin4(
                ~top=px(10),
                ~bottom=px(1),
                ~left=px(5),
                ~right=px(15),
              ),
            ],
          )
        )
      />
    </Section>
    <Section name="grid">
      <div
        className=Css.(
          style([
            width(pct(100.)),
            height(px(500)),
            display(grid),
            gridTemplateColumns([px(150), auto, px(150)]),
            gridTemplateRows([px(60), auto]),
          ])
        )>
        <div
          className=Css.(
            style([
              gridColumnStart(1),
              gridColumnEnd(4),
              background(red),
              gridRowStart(1),
              gridRowEnd(1),
            ])
          )
        />
        <div
          className=Css.(
            style([background(blue), gridColumn(1, 1), gridRow(2, 2)])
          )
        />
        <div
          className=Css.(
            style([
              background(green),
              gridColumn(2, 2),
              gridRow(2, 2),
              display(inlineGrid),
              gridTemplateColumns([px(50), auto]),
              gridTemplateRows([px(40), auto]),
            ])
          )>
          <div
            className=Css.(
              style([background(yellow), gridRow(1, 1), gridColumn(2, 2)])
            )
          />
          <div
            className=Css.(
              style([background(green), gridRow(1, 2), gridColumn(1, 1)])
            )
          />
          <div
            className=Css.(
              style([background(purple), gridRow(2, 2), gridColumn(2, 2)])
            )
          />
        </div>
        <div
          className=Css.(
            style([
              gridColumnStart(3),
              gridColumnEnd(3),
              background(blue),
              gridRowStart(2),
              gridRowEnd(2),
            ])
          )
        />
      </div>
      <div className=Css.(style([display(`grid), gridAutoFlow(`row)]))>
        <div className=Css.(style([background(purple)]))>
          {text("grid auto direction row 1")}
        </div>
        <div className=Css.(style([background(green)]))>
          {text("grid auto direction row 2")}
        </div>
      </div>
      <div
        className=Css.(
          style([
            display(`grid),
            gridTemplateColumns([100->px, `repeat((`num(2), 60->px))]),
          ])
        )>
        <div className=Css.(style([background(purple)]))>
          {text("Grid track repeat")}
        </div>
        <div className=Css.(style([background(green)]))>
          {text("two times")}
        </div>
        <div className=Css.(style([background(red)]))>
          {text("three times")}
        </div>
      </div>
      <div
        className=Css.(style([display(`grid), gridAutoColumns(100->px)]))>
        <div className=Css.(style([background(purple)]))>
          {text("Grid auto columns (100px)")}
        </div>
        <div className=Css.(style([background(green)]))>
          {text("100px")}
        </div>
        <div className=Css.(style([background(blue)]))>
          {text("100px")}
        </div>
      </div>
    </Section>
    <Section name="flexbox">
      <div
        className=Css.(
          style([
            flexDirection(column),
            flexGrow(1.),
            alignItems(stretch),
            selector("& > *", [marginBottom(px(10)), width(pct(100.))]),
          ])
        )>
        <div
          className=Css.(
            style([
              display(flexBox),
              flexDirection(row),
              background(gray),
              alignItems(flexStart),
              justifyContent(flexEnd),
            ])
          )>
          <div
            className=Css.(
              style(
                redBox
                @ [
                  order(1),
                  flexGrow(1.),
                  flexShrink(1.),
                  flexBasis(auto),
                ],
              )
            )
          />
          <div className=Css.(style(redBox @ [flex(none)])) />
          <div
            className=Css.(
              style(
                redBox
                @ [order(1), flex3(~grow=1.5, ~shrink=0.8, ~basis=100->px)],
              )
            )
          />
          <div className=Css.(style(redBox @ [alignSelf(flexEnd)])) />
          <div className={Css.style(redBox)} />
        </div>
        <div
          className=Css.(
            style([
              display(flexBox),
              flexDirection(column),
              background(gray),
              alignItems(baseline),
              justifyContent(flexStart),
            ])
          )>
          <div className={Css.style(redBox)} />
          <div className={Css.style(redBox)} />
          <div className={Css.style(redBox)} />
        </div>
        <div
          className=Css.(
            style([
              display(flexBox),
              flexDirection(rowReverse),
              background(gray),
              alignItems(center),
              justifyContent(spaceBetween),
            ])
          )>
          <div className={Css.style(redBox)} />
          <div
            className=Css.(
              style(redBox @ [height(px(50)), width(px(50))])
            )
          />
          <div className={Css.style(redBox)} />
        </div>
        <div
          className=Css.(
            style([
              display(flexBox),
              flexDirection(columnReverse),
              background(gray),
              alignItems(flexEnd),
              justifyContent(flexEnd),
            ])
          )>
          <div className={Css.style(redBox)} />
          <div
            className=Css.(
              style(redBox @ [height(px(50)), width(px(50))])
            )
          />
          <div className={Css.style(redBox)} />
        </div>
        <div
          className=Css.(
            style([
              display(flexBox),
              flexDirection(row),
              background(gray),
              alignItems(stretch),
              justifyContent(spaceAround),
            ])
          )>
          <div className={Css.style(redBox)} />
          <div
            className=Css.(
              style(redBox @ [height(px(50)), width(px(50))])
            )
          />
          <div className={Css.style(redBox)} />
        </div>
        <div
          className=Css.(
            style([
              display(flexBox),
              flexDirection(row),
              background(gray),
              alignItems(stretch),
              justifyContent(spaceEvenly),
            ])
          )>
          <div className={Css.style(redBox)} />
          <div
            className=Css.(
              style(redBox @ [height(px(50)), width(px(50))])
            )
          />
          <div className={Css.style(redBox)} />
        </div>
      </div>
    </Section>
    <Section name="float">
      <div className=Css.(style(redBox @ [float(`left), clear(`right)])) />
      <div className=Css.(style(redBox @ [float(`right), clear(`left)])) />
      <div className=Css.(style(redBox @ [float(none), clear(both)])) />
    </Section>
    <Section name="overflow">
      <div className=Css.(style(redBox @ [overflow(hidden)])) />
      <div className=Css.(style(redBox @ [overflow(visible)])) />
      <div className=Css.(style(redBox @ [overflow(auto)])) />
      <div className=Css.(style(redBox @ [overflow(scroll)])) />
    </Section>
    <Section name="border">
      <div
        className=Css.(
          style(
            redBox @ [border(px(5), solid, blue), borderRadius(px(1000))],
          )
        )
      />
      <div
        className=Css.(
          style(
            redBox
            @ [
              border(px(5), solid, green),
              borderTopRightRadius(px(1000)),
              borderTopLeftRadius(px(1000)),
              borderBottomRightRadius(px(1000)),
              borderBottomLeftRadius(px(1000)),
            ],
          )
        )
      />
      <div
        className=Css.(
          style(
            redBox
            @ [
              borderTop(px(5), dashed, hex("FFF")),
              borderRight(px(5), dotted, rgb(0, 0, 0)),
              borderBottom(px(5), none, green),
              borderLeft(px(5), solid, blue),
            ],
          )
        )
      />
      <div
        className=Css.(
          style(
            redBox
            @ [borderWidth(px(5)), borderStyle(solid), borderColor(blue)],
          )
        )
      />
      <div
        className=Css.(
          style(
            redBox
            @ [
              borderTopWidth(px(5)),
              borderTopStyle(solid),
              borderTopColor(blue),
            ],
          )
        )
      />
      <div
        className=Css.(
          style(
            redBox
            @ [
              borderBottomWidth(px(5)),
              borderBottomStyle(solid),
              borderBottomColor(blue),
            ],
          )
        )
      />
      <div
        className=Css.(
          style(
            redBox
            @ [
              borderLeftWidth(px(5)),
              borderLeftStyle(solid),
              borderLeftColor(blue),
            ],
          )
        )
      />
      <div
        className=Css.(
          style(
            redBox
            @ [
              borderRightWidth(px(5)),
              borderRightStyle(solid),
              borderRightColor(blue),
            ],
          )
        )
      />
    </Section>
    <Section name="background">
      <div
        className=Css.(
          style(
            redBox
            @ [
              background(red),
              backgroundAttachment(scroll),
              backgroundClip(borderBox),
              backgroundOrigin(borderBox),
              backgroundPosition(pct(50.), pct(50.)),
              backgroundRepeat(noRepeat),
              backgroundSize(size(px(100), px(100))),
            ],
          )
        )
      />
      <div
        className=Css.(
          style(
            redBox
            @ [
              background(radialGradient([(zero, red), (pct(10.), blue)])),
              backgroundAttachment(fixed),
              backgroundClip(contentBox),
              backgroundOrigin(contentBox),
              backgroundRepeat(repeat),
              backgroundSize(auto),
            ],
          )
        )
      />
      <div
        className=Css.(
          style(
            redBox
            @ [
              background(url("./img-29.jpg")),
              backgroundAttachment(local),
              backgroundClip(paddingBox),
              backgroundOrigin(paddingBox),
              backgroundRepeat(repeatX),
              backgroundSize(cover),
            ],
          )
        )
      />
      <div
        className=Css.(
          style(
            redBox
            @ [
              backgroundColor(rgb(0, 0, 255)),
              backgroundImage(
                linearGradient(
                  deg(45.),
                  [(zero, green), (pct(50.), red), (pct(100.), yellow)],
                ),
              ),
              backgroundRepeat(repeatY),
              backgroundSize(contain),
            ],
          )
        )
      />
    </Section>
    <Section name="cursor">
      <div className=Css.(style(redBox @ [cursor(`auto)]))>
        {text("auto")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`default)]))>
        {text("default")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`none)]))>
        {text("none")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`contextMenu)]))>
        {text("context menu")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`help)]))>
        {text("help")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`pointer)]))>
        {text("pointer")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`progress)]))>
        {text("progress")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`wait)]))>
        {text("wait")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`cell)]))>
        {text("cell")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`crosshair)]))>
        {text("crosshair")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`text)]))>
        {text("text")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`verticalText)]))>
        {text("vert text")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`alias)]))>
        {text("alias")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`copy)]))>
        {text("copy")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`move)]))>
        {text("move")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`noDrop)]))>
        {text("no drop")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`notAllowed)]))>
        {text("not allowed")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`grab)]))>
        {text("grab")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`grabbing)]))>
        {text("grabbing")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`allScroll)]))>
        {text("all scroll")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`colResize)]))>
        {text("col resize")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`rowResize)]))>
        {text("row resize")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`nResize)]))>
        {text("n resize")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`eResize)]))>
        {text("e resize")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`sResize)]))>
        {text("s resize")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`wResize)]))>
        {text("w resize")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`neResize)]))>
        {text("ne resize")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`nwResize)]))>
        {text("nw resize")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`seResize)]))>
        {text("se resize")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`swResize)]))>
        {text("sw resize")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`ewResize)]))>
        {text("ew resize")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`nsResize)]))>
        {text("ns resize")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`neswResize)]))>
        {text("nesw resize")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`nwseResize)]))>
        {text("nwse resize")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`zoomIn)]))>
        {text("zoom in")}
      </div>
      <div className=Css.(style(redBox @ [cursor(`zoomOut)]))>
        {text("zoom out")}
      </div>
    </Section>
    <Section name="list">
      <ul>
        <li className=Css.(style([listStyle(`disc, inside, none)])) />
        <li className=Css.(style([listStyleType(`circle)])) />
        <li className=Css.(style([listStyleType(`square)])) />
        <li className=Css.(style([listStyleType(`decimal)])) />
        <li className=Css.(style([listStyleType(`lowerAlpha)])) />
        <li className=Css.(style([listStyleType(`upperAlpha)])) />
        <li className=Css.(style([listStyleType(`lowerGreek)])) />
        <li className=Css.(style([listStyleType(`lowerLatin)])) />
        <li className=Css.(style([listStyleType(`upperLatin)])) />
        <li className=Css.(style([listStyleType(`lowerRoman)])) />
        <li className=Css.(style([listStyleType(`upperRoman)])) />
        <li
          className=Css.(
            style([
              listStyleType(`disc),
              listStylePosition(inside),
              listStyleImage(url("./facebook.png")),
            ])
          )
        />
      </ul>
    </Section>
    <Section name="outline">
      <div
        className=Css.(style(redBox @ [outline(px(5), `double, green)]))
      />
      <div
        className=Css.(
          style(
            redBox
            @ [
              outlineStyle(solid),
              outlineWidth(px(5)),
              outlineColor(green),
              outlineOffset(px(5)),
            ],
          )
        )
      />
      <div
        className=Css.(style(redBox @ [outline(px(5), `double, red)]))
      />
      <div className=Css.(style(redBox @ [outline(px(5), `ridge, red)])) />
    </Section>
    <Section name="transform">
      <div className=Css.(style(redBox @ [opacity(0.5)])) />
      <div
        className=Css.(
          style(
            redBox @ [perspective(px(500)), transform(rotate(deg(10.)))],
          )
        )
      />
      <div
        className=Css.(
          style(
            redBox
            @ [
              transforms([
                translate(px(10), pct(10.)),
                skew(deg(10.), deg(10.)),
              ]),
            ],
          )
        )
      />
      <div
        className=Css.(
          style(
            redBox
            @ [
              transform(rotate(deg(19.))),
              transformOrigin(pct(50.), pct(50.)),
              transformStyle(`preserve3d),
              perspective(px(900)),
              perspectiveOrigin(pct(10.), pct(10.)),
            ],
          )
        )
      />
      <div
        className=Css.(
          style(
            redBox
            @ [
              transform(translate(px(10), pct(10.))),
              transformOrigin3d(px(10), px(10), px(10)),
            ],
          )
        )
      />
    </Section>
    <Section name="transition">
      <div
        className=Css.(
          style(
            redBox
            @ [
              transition(
                ~duration=300,
                ~delay=300,
                ~timingFunction=easeInOut,
                "transform",
              ),
            ],
          )
        )
      />
      <div
        className=Css.(
          style(
            redBox
            @ [
              transitionProperty("height"),
              transitionDelay(300),
              transitionDuration(300),
              transitionTimingFunction(linear),
            ],
          )
        )
      />
    </Section>
    <Section name="text">
      <p
        className=Css.(
          style([
            color(black),
            fontFamily("Helvetica, sans-serif"),
            fontSize(pt(18)),
            fontVariant(`smallCaps),
            fontStyle(italic),
            fontWeight(`num(300)),
            letterSpacing(px(3)),
            lineHeight(`abs(2.)),
            textAlign(`left),
            textDecoration(underline),
            textDecorationColor(pink),
            textDecorationStyle(wavy),
            textIndent(px(10)),
            textOverflow(clip),
            textShadow(Shadow.text(~y=px(3), ~blur=px(2), black)),
            textTransform(capitalize),
            verticalAlign(sub),
            whiteSpace(normal),
            wordBreak(breakAll),
            wordSpacing(px(20)),
            wordWrap(breakWord),
          ])
        )>
        {text(
           "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.",
         )}
      </p>
      <h2 className=Css.(style([width(pct(100.))]))>
        {text("Named Font weights")}
      </h2>
      <span
        className=Css.(
          style([
            fontWeight(thin),
            paddingRight(px(10)),
            borderRight(px(1), solid, black),
          ])
        )>
        {text("thin")}
      </span>
      <span className=Css.(style([fontWeight(extraLight), ...fontItem]))>
        {text("extra light")}
      </span>
      <span className=Css.(style([fontWeight(light), ...fontItem]))>
        {text("light")}
      </span>
      <span className=Css.(style([fontWeight(normal), ...fontItem]))>
        {text("normal")}
      </span>
      <span className=Css.(style([fontWeight(medium), ...fontItem]))>
        {text("medium")}
      </span>
      <span className=Css.(style([fontWeight(semiBold), ...fontItem]))>
        {text("semiBold")}
      </span>
      <span className=Css.(style([fontWeight(bold), ...fontItem]))>
        {text("bold")}
      </span>
      <span className=Css.(style([fontWeight(extraBold), ...fontItem]))>
        {text("extra bold")}
      </span>
      <span className=Css.(style([fontWeight(`black), ...fontItem]))>
        {text("black")}
      </span>
      <span className=Css.(style([fontWeight(lighter), ...fontItem]))>
        {text("lighter")}
      </span>
      <span className=Css.(style([fontWeight(bolder), ...fontItem]))>
        {text("bolder")}
      </span>
    </Section>
    <Section name="animation">
      <div
        className=Css.(
          style(
            redBox
            @ [
              animation(
                ~duration=300,
                ~delay=300,
                ~direction=reverse,
                ~timingFunction=linear,
                ~fillMode=forwards,
                ~playState=running,
                ~iterationCount=infinite,
                spin,
              ),
            ],
          )
        )
      />
      <div
        className=Css.(
          style(
            redBox
            @ [
              animations([
                Animation.shorthand(
                  ~duration=300,
                  ~iterationCount=infinite,
                  spin,
                ),
                Animation.shorthand(
                  ~duration=300,
                  ~iterationCount=infinite,
                  scaleAnimation,
                ),
              ]),
            ],
          )
        )
      />
      <div
        className=Css.(
          style(
            redBox
            @ [
              animationName(spin),
              animationTimingFunction(easeIn),
              animationDuration(300),
              animationDelay(300),
              animationDirection(normal),
              animationFillMode(backwards),
              animationPlayState(paused),
              animationIterationCount(count(5)),
            ],
          )
        )
      />
    </Section>
    <Section name="cascading">
      {text("inherit")}
      <div
        className=Css.(
          style([
            display(inherit_),
            position(inherit_),
            fontSize(inherit_),
            fontStyle(inherit_),
            lineHeight(inherit_),
          ])
        )
      />
      {text("unset")}
      <div
        className=Css.(
          style([
            display(unset),
            position(unset),
            fontSize(unset),
            fontStyle(unset),
            lineHeight(unset),
          ])
        )
      />
    </Section>
    <Section name="columns">
      <p className=Css.(style([columnCount(count(10))]))>
        {text(
           "This is a bunch of text split into columns
             using the CSS `column-count` property. The text
             is equally distributed over the columns.",
         )}
      </p>
    </Section>
    <Section name="resize">
      <textarea className=Css.(style([resize(none)]))>
        "Can't resize textarea"->text
      </textarea>
      <div
        className=Css.(
          style([
            marginLeft(px(20)),
            overflow(scroll),
            resize(horizontal),
          ])
        )>
        "Resizable div (horizontal)"->text
      </div>
      <div
        className=Css.(
          style([marginLeft(px(20)), overflow(scroll), resize(vertical)])
        )>
        "Resizable div (vertical)"->text
      </div>
    </Section>
    <Section name="content">
      <a
        href="https://github.com/SentiaAnalytics/bs-css"
        className=Css.(
          style([
            before([
              contentRule("external "),
              backgroundColor(red),
              display(inlineBlock),
              flexBasis(content /*for test*/),
            ]),
          ])
        )>
        {text("link")}
      </a>
      <div
        className=Css.(
          style([
            position(relative),
            marginLeft(px(20)),
            after([
              contentRule(""),
              position(absolute),
              top(zero),
              left(zero),
              width(pct(100.)),
              height(pct(100.)),
              border(px(1), solid, black),
            ]),
          ])
        )>
        {text("empty content")}
      </div>
    </Section>
    <Section name="insertRule, the ultimate escape hatch">
      <div className="raw-css" />
    </Section>
    <Section name="merging style names">
      <button className=mergedStyles> {text("Merged")} </button>
    </Section>
    <Section name="filter">
      <div className=Css.(style(redBox @ [filter([`blur(`px(10))])])) />
      <div className=Css.(style(redBox @ [filter([`brightness(50.)])])) />
      <div className=Css.(style(redBox @ [filter([`contrast(50.)])])) />
      <div
        className=Css.(
          style(
            redBox
            @ [
              filter([
                `dropShadow((
                  `px(3),
                  `px(3),
                  `px(3),
                  `rgb((200, 100, 100)),
                )),
              ]),
            ],
          )
        )
      />
      <div className=Css.(style(redBox @ [filter([`grayscale(50.)])])) />
      <div
        className=Css.(style(redBox @ [filter([`hueRotate(`deg(180.))])]))
      />
      <div className=Css.(style(redBox @ [filter([`invert(50.)])])) />
      <div className=Css.(style(redBox @ [filter([`opacity(50.)])])) />
      <div className=Css.(style(redBox @ [filter([`saturate(50.)])])) />
      <div className=Css.(style(redBox @ [filter([`sepia(50.)])])) />
      <div
        className=Css.(
          style(
            redBox
            @ [
              filter([
                `sepia(50.),
                `saturate(50.),
                `dropShadow((
                  `px(3),
                  `px(3),
                  `px(3),
                  `rgb((200, 100, 100)),
                )),
              ]),
            ],
          )
        )
      />
      <svg height="0" className=Css.(style([display(`none)]))>
        <filter id="f1"> <feGaussianBlur stdDeviation="3" /> </filter>
      </svg>
      <div className=Css.(style(redBox @ [filter([`url("#f1")])])) />
    </Section>
    <Section name="direction">
      <Section name="ltr">
        <div className=Css.(style([direction(`ltr), display(`flex)]))>
          <div className=Css.(style(redBox))> {"1" |> text} </div>
          <div className=Css.(style(redBox))> {"2" |> text} </div>
          <div className=Css.(style(redBox))> {"3" |> text} </div>
          <div className=Css.(style(redBox))> {"4" |> text} </div>
        </div>
      </Section>
      <Section name="rtl">
        <div className=Css.(style([direction(`rtl), display(`flex)]))>
          <div className=Css.(style(redBox))> {"1" |> text} </div>
          <div className=Css.(style(redBox))> {"2" |> text} </div>
          <div className=Css.(style(redBox))> {"3" |> text} </div>
          <div className=Css.(style(redBox))> {"4" |> text} </div>
        </div>
      </Section>
      <Section name="unset">
        <div className=Css.(style([direction(`unset), display(`flex)]))>
          <div className=Css.(style(redBox))> {"1" |> text} </div>
          <div className=Css.(style(redBox))> {"2" |> text} </div>
          <div className=Css.(style(redBox))> {"3" |> text} </div>
          <div className=Css.(style(redBox))> {"4" |> text} </div>
        </div>
      </Section>
    </Section>
    <Section name="object-fit">
      <img
        className=Css.(style(redBox @ [objectFit(`fill)]))
        src="./img-29.jpg"
      />
      <img
        className=Css.(style(redBox @ [objectFit(`contain)]))
        src="./img-29.jpg"
      />
      <img
        className=Css.(style(redBox @ [objectFit(`cover)]))
        src="./img-29.jpg"
      />
      <img
        className=Css.(style(redBox @ [objectFit(`none)]))
        src="./img-29.jpg"
      />
      <img
        className=Css.(style(redBox @ [objectFit(`scaleDown)]))
        src="./img-29.jpg"
      />
      <img
        className=Css.(style(redBox @ [objectFit(`inherit_)]))
        src="./img-29.jpg"
      />
      <img
        className=Css.(style(redBox @ [objectFit(`initial)]))
        src="./img-29.jpg"
      />
      <img
        className=Css.(style(redBox @ [objectFit(`unset)]))
        src="./img-29.jpg"
      />
    </Section>
  </div>;
