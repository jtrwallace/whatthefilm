var router = require('koa-router')();

router.get('/', async function (ctx, next) {
  ctx.state = {
    title: 'What The Film'
  };

  await ctx.render('index', {
  });
})
module.exports = router;
